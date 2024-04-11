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

const int MAXN=13;
const int MAXM=12;
const int MAXQ=100;

int n,m,nq;
int u[MAXM],v[MAXM];
int a[MAXQ],b[MAXQ],c[MAXQ];

ll mem[1<<MAXN][MAXN];
ll go(int mask,int root) {
	if(mask==0) return 1;
	ll &ret=mem[mask>>1][root];
	if(ret==-1) {
		ret=0;
		int other=(1<<n)-1-mask;
		for(int x=(other+1)&~other;x<=mask;x=(x+other+1)&~other) {
			if((mask&(-mask)&x)==0) continue;
			int y=mask^x^(1<<root),nroot=-1;
			bool ok=true;
			REP(i,nq) {
				bool ax=(x>>a[i])&1,bx=(x>>b[i])&1,cx=(x>>c[i])&1;
				bool ay=(y>>a[i])&1,by=(y>>b[i])&1,cy=(y>>c[i])&1;
				if(cx!=(ax&&bx)||cy&&(ax||bx)&&root!=c[i]) { ok=false; break; }
			}
			if(!ok) continue;
			REP(i,m) {
				bool ux=(x>>u[i])&1,vx=(x>>v[i])&1;
				if(ux&&!vx) if(root!=v[i]||nroot!=-1&&nroot!=u[i]) { ok=false; break; } else nroot=u[i];
				if(vx&&!ux) if(root!=u[i]||nroot!=-1&&nroot!=v[i]) { ok=false; break; } else nroot=v[i];
			}
			if(!ok) continue;
			//printf("\t%d %x -> %d %x\n",root,mask,nroot,x);
			if(nroot!=-1) ret+=go(x^(1<<nroot),nroot)*go(y^(1<<root),root);
			if(nroot==-1) REP(nroot,n) if((x>>nroot)&1) ret+=go(x^(1<<nroot),nroot)*go(y^(1<<root),root);
		}
		//printf("%d %x = %I64d\n",root,mask,ret);
	}
	return ret;
}

void run() {
	scanf("%d%d%d",&n,&m,&nq);
	REP(i,m) scanf("%d%d",&u[i],&v[i]),--u[i],--v[i];
	REP(i,nq) scanf("%d%d%d",&a[i],&b[i],&c[i]),--a[i],--b[i],--c[i];
	memset(mem,-1,sizeof(mem));
	printf("%I64d\n",go((1<<n)-1-(1<<0),0));
}

int main() {
	run();
	return 0;
}