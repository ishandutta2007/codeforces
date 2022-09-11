#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
using namespace std;  

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;  
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXVAL=1000000;

int pmn[MAXVAL+1];
int id[MAXVAL+1];

int nstate; ll mxdiv;
vector<vector<int>> states;
vector<ll> dv;
vector<int> dvidx;
vector<ll> dvlst;
map<vector<int>,int> mp;

vector<vector<int>> adj;
vector<vector<int>> dp;


void genextrastates(vector<int> &cur,int at,int rem) {
	if(!mp.count(cur)) { int cid=nstate++; mp[cur]=cid; states.PB(cur); }
	for(int i=at;i>=1;--i) if(i<=rem) { cur.PB(i); genextrastates(cur,i,rem-i); cur.pop_back(); }
}

void precalc() {
	REPE(i,MAXVAL) pmn[i]=i; FORE(i,2,MAXVAL) if(pmn[i]==i) for(int j=i+i;j<=MAXVAL;j+=i) pmn[j]=min(pmn[j],pmn[i]);
	nstate=0; states.clear();
	FORE(i,1,MAXVAL) {
		vector<int> cur;
		{ int x=i; while(x!=1) { int p=pmn[x],cnt=0; while(x%p==0) x/=p,++cnt; cur.PB(cnt); } }
		sort(cur.begin(),cur.end()); reverse(cur.begin(),cur.end());
		if(!mp.count(cur)) { int cid=nstate++; mp[cur]=cid; states.PB(cur); }
		id[i]=mp[cur];
	}
	int ostate=nstate;
	//printf("nstate=%d\n",nstate);
	{ vector<int> cur; genextrastates(cur,28,28); }
	//{ vector<int> cur; cur.PB(12); cur.PB(4); cur.PB(3); if(mp.count(cur)) printf("mp=%d\n",mp[cur]); }
	//printf("nstate=%d\n",nstate);
	mxdiv=0; dv=vector<ll>(nstate);
	REPSZ(i,states) {
		ll cur=1; REPSZ(j,states[i]) cur*=states[i][j]+1;
		mxdiv=max(mxdiv,cur); dv[i]=cur;
		//printf("%d\n",cur);
	}
	dvlst.clear(); REP(i,nstate) dvlst.PB(dv[i]); sort(dvlst.begin(),dvlst.end()); dvlst.erase(unique(dvlst.begin(),dvlst.end()),dvlst.end());
	dvidx=vector<int>(nstate); REP(i,nstate) dvidx[i]=lower_bound(dvlst.begin(),dvlst.end(),dv[i])-dvlst.begin();
	//printf("nstate=%d mxdiv=%lld (%d different)\n",nstate,mxdiv,SZ(dvlst));
	adj=vector<vector<int>>(nstate);
	REP(i,nstate) {
		REPE(j,SZ(states[i])) REP(k,2) {
			vector<int> cur=states[i]; 
			if(j<SZ(cur)) { if(k==0) ++cur[j]; else { --cur[j]; if(cur[j]==0) cur.erase(cur.begin()+j); } } else { cur.PB(1); }
			sort(cur.begin(),cur.end()); reverse(cur.begin(),cur.end());
			if(!mp.count(cur)) continue;
			adj[i].PB(mp[cur]);
		}
		sort(adj[i].begin(),adj[i].end()); adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
	}
	dp=vector<vector<int>>(ostate,vector<int>(SZ(dvlst),INT_MAX));
	REP(i,ostate) {
		queue<int> q; vector<int> d(nstate,INT_MAX); d[i]=0; q.push(i);
		while(!q.empty()) {
			int at=q.front(); q.pop();
			REPSZ(j,adj[at]) {
				int to=adj[at][j];
				if(d[to]!=INT_MAX) continue;
				//if(i==10) printf("%d: %d->%d\n",i,at,to);
				d[to]=d[at]+1; q.push(to);
			}
		}
		REP(j,nstate) { int k=dvidx[j]; dp[i][k]=min(dp[i][k],d[j]); }
	}
	//int dmx=0; REP(i,ostate) { FOR(j,i+1,ostate) { int cur=INT_MAX; REPSZ(k,dvlst) if(dp[i][k]!=INT_MAX&&dp[j][k]!=INT_MAX) { cur=min(cur,dp[i][k]+dp[j][k]); if(cur<=dmx) break; } dmx=max(dmx,cur); } } printf("dmx=%d\n",dmx);
	//int smx=0; REP(i,ostate) { int cur=0; REPSZ(j,states[i]) cur+=states[i][j]; smx=max(smx,cur); } printf("smx=%d\n",smx);
}

void run() {
	precalc();
	int n; scanf("%d",&n);
	REP(i,n) {
		int a,b; scanf("%d%d",&a,&b);
		a=id[a],b=id[b];
		//int idx=lower_bound(dvlst.begin(),dvlst.end(),12*4*3)-dvlst.begin(); printf("%d: %lld\n",idx,dvlst[idx]); printf("%d %d\n",dp[a][idx],dp[b][idx]);
		//printf("aid=%d bid=%d\n",a,b);
		int ans=INT_MAX; REPSZ(k,dvlst) if(dp[a][k]!=INT_MAX&&dp[b][k]!=INT_MAX) ans=min(ans,dp[a][k]+dp[b][k]);
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}