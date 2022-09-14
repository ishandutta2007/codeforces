#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=5000;

int n;
int x[MAXN];

int nxt[MAXN];
pair<int,int> o[MAXN];

int id[MAXN],nid;

int v[MAXN+1];
vector<int> c[MAXN+1];

int process(int i) {
	int val=x[i]; int cid=nid++; REP(k,n) if(x[k]==val) id[k]=cid; v[cid]=val;
	for(int at=i,to;at<n;at=to) {
		while(true) {
			to=at+1; while(to<n&&id[to]!=cid) ++to; if(to>=n) break;
			bool any=false;
			FORE(j,at+1,to-1) if(nxt[j]>to) {
				int nval=x[j]; REP(k,n) if(x[k]==nval) id[k]=cid; v[cid]^=nval;
				any=true;
			}
			if(any) continue;
			FORE(j,at+1,to-1) if(id[j]==-1) {
				c[cid].PB(process(j));
			}
			break;
		}
	}
	return cid;
}

pair<int,int> solve(int at) {
	int all=v[at],sum=0;
	REPSZ(i,c[at]) {
		int to=c[at][i];
		pair<int,int> res=solve(to);
		all^=res.first;
		sum+=res.second;
	}
	return MP(all,max(all,sum));
}



void printtree(int at,int d=0) {
	REP(i,d) printf("  "); printf("%d\n",v[at]);
	REPSZ(i,c[at]) printtree(c[at][i],d+1);
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);

	REP(i,n) o[i]=MP(x[i],i); sort(o,o+n); REP(i,n) nxt[o[i].second]=i+1<n&&o[i+1].first==o[i].first?o[i+1].second:-1;
	//REP(i,n) printf("%d ",nxt[i]); puts("");

	REP(i,n) id[i]=-1; nid=0;
	int root=nid++; v[root]=0;
	REP(i,n) if(id[i]==-1) c[root].PB(process(i));
	//printtree(root);

	pair<int,int> res=solve(root);
	printf("%d\n",res.second);
}

int main() {
	run();
	return 0;
}