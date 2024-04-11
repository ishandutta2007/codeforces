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

const int MAXN=300000;
const int MAXLG=18;
const int MAXK=5;
const int MAXLEADER=MAXK-1;
const int MAXVAL=MAXN;
typedef struct Z { int leader[MAXLEADER],rem[MAXLEADER]; } S;

int n,nq;
int a[MAXN];
vector<int> b[MAXVAL+1];

Z res[MAXLG+1][MAXN];
Z calc(int x) { Z ret; REP(i,4) ret.leader[i]=-1,ret.rem[i]=0; ret.leader[0]=x,ret.rem[0]=1; return ret; }
Z combine(const Z &a,const Z &b) {
	Z ret=a;
	REP(j,MAXLEADER) {
		int idx=-1; REP(i,MAXLEADER) if(ret.leader[i]==b.leader[j]) { idx=i; break; } if(idx!=-1) { ret.rem[idx]+=b.rem[j]; continue; }
		int mnidx=0; FOR(i,1,MAXLEADER) if(ret.rem[i]<ret.rem[mnidx]) mnidx=i; int sub=min(ret.rem[mnidx],b.rem[j]);
		REP(i,MAXLEADER) if((ret.rem[i]-=sub)==0) ret.leader[i]=-1;
		if(b.rem[j]>sub) { bool found=false; REP(i,MAXLEADER) if(ret.leader[i]==-1) { ret.leader[i]=b.leader[j],ret.rem[i]=b.rem[j]-sub,found=true; break; } assert(found); }
	}
	return ret;
}

Z query(int l,int r) {
	Z ret; REP(i,MAXLEADER) ret.leader[i]=-1,ret.rem[i]=0;
	for(int k=MAXLG;k>=0;--k) if(l+(1<<k)<=r) ret=combine(ret,res[k][l]),l+=1<<k;
	return ret;
}

int getcnt(int v,int l,int r) {
	return lower_bound(b[v].begin(),b[v].end(),r)-lower_bound(b[v].begin(),b[v].end(),l);
}

void run() {
	scanf("%d%d",&n,&nq); REP(i,n) scanf("%d",&a[i]);
	REP(i,n) b[a[i]].PB(i);

	REP(i,n) res[0][i]=calc(a[i]);
	FORE(k,1,MAXLG) REPE(i,n-(1<<k)) res[k][i]=combine(res[k-1][i],res[k-1][i+(1<<(k-1))]);

	REP(i,nq) {
		int l,r,k; scanf("%d%d%d",&l,&r,&k); --l;
		Z res=query(l,r);
		int ans=-1,need=(r-l)/k+1;
		REP(j,MAXLEADER) if(res.leader[j]!=-1) {
			int cnt=getcnt(res.leader[j],l,r);
			if(cnt>=need&&(ans==-1||res.leader[j]<ans)) ans=res.leader[j];
		}
		printf("%d\n",ans);
	}
}

int main() {
	run();
	return 0;
}