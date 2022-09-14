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
const int MAXM=5000;
const int MAXW=5000;

int n,m,nw,nq;
int ghead[MAXN],gnxt[2*MAXM],gto[2*MAXM];
int whead[MAXN],wnxt[MAXW],whave[MAXW],wcost[MAXW];
int q[MAXN],qhead,qtail,d[MAXN];

priority_queue<pair<int,int> > pq;

int solve(int t,int want,int mxcost) {
	int left=want; ll cost=0;
	qhead=qtail=0; REP(i,n) d[i]=INT_MAX; pq=priority_queue<pair<int,int> >();
	q[qhead++]=t; d[t]=0;
	while(qtail<qhead) {
		int at=q[qtail++];
		for(int x=whead[at];x!=-1;x=wnxt[x]) {
			int rem=whave[x],cur=min(rem,left),now=0; left-=cur,rem-=cur,now+=cur,cost+=(ll)cur*wcost[x];
			while(rem>0&&SZ(pq)>0&&wcost[x]<pq.top().first) {
				pair<int,int> top=pq.top(); pq.pop(); int cur=min(rem,top.second);
				top.second-=cur,rem-=cur,now+=cur,cost+=(ll)cur*(wcost[x]-top.first); if(top.second!=0) pq.push(top);
			}
			pq.push(MP(wcost[x],now));
		}
		if(left==0&&cost<=mxcost) return d[at];
		for(int x=ghead[at];x!=-1;x=gnxt[x]) {
			int to=gto[x]; if(d[to]!=INT_MAX) continue;
			d[to]=d[at]+1; q[qhead++]=to;
		}
	}
	return INT_MAX;
}

void run() {
	scanf("%d%d",&n,&m); REP(i,n) ghead[i]=-1,whead[i]=-1;
	REP(i,m) {
		int a,b; scanf("%d%d",&a,&b); --a,--b;
		gnxt[2*i+0]=ghead[a]; ghead[a]=2*i+0; gto[2*i+0]=b;
		gnxt[2*i+1]=ghead[b]; ghead[b]=2*i+1; gto[2*i+1]=a;
	}
	scanf("%d",&nw);
	REP(i,nw) {
		int a; scanf("%d%d%d",&a,&whave[i],&wcost[i]); --a;
		wnxt[i]=whead[a]; whead[a]=i;
	}
	scanf("%d",&nq);
	REP(i,nq) {
		int a,want,mxcost; scanf("%d%d%d",&a,&want,&mxcost); --a;
		int ret=solve(a,want,mxcost);
		printf("%d\n",ret==INT_MAX?-1:ret);
	}
}


int main() {
	run();
	return 0;
}