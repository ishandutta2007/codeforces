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

const int MAXN=200000;
const int MAXM=200000;

int n,m;
ull A,B,C;
vector<int> adj[MAXN];

int ntrilo[MAXN],ntrimi[MAXN],ntrihi[MAXN];
vector<int> adj2[MAXN]; // only nodes with larger degree or same degree and higher id

bool exists(int a,int b) {
	int idx=lower_bound(adj[a].begin(),adj[a].end(),b)-adj[a].begin();
	return idx<SZ(adj[a])&&adj[a][idx]==b;
}

void counttriangles() {
	REP(i,n) adj2[i].clear(),ntrilo[i]=ntrimi[i]=ntrihi[i]=0;
	REP(i,n) REPSZ(j,adj[i]) { int k=adj[i][j]; if(SZ(adj[i])<SZ(adj[k])||SZ(adj[i])==SZ(adj[k])&&i<k) adj2[i].PB(k); }
	//int numtri=0;
	REP(i,n) REPSZ(j,adj2[i]) FORSZ(k,j+1,adj2[i]) {
		int x=i,y=adj2[i][j],z=adj2[i][k];
		if(!exists(y,z)) continue;
		//++numtri;
		if(x<y&&y<z) {
			++ntrilo[x],++ntrimi[y],++ntrihi[z];
		} else if(x<z&&z<y) {
			++ntrilo[x],++ntrimi[z],++ntrihi[y];
		} else if(y<x&&x<z) {
			++ntrilo[y],++ntrimi[x],++ntrihi[z];
		} else if(y<z&&z<x) {
			++ntrilo[y],++ntrimi[z],++ntrihi[x];
		} else if(z<x&&x<y) {
			++ntrilo[z],++ntrimi[x],++ntrihi[y];
		} else if(z<y&&y<x) {
			++ntrilo[z],++ntrimi[y],++ntrihi[x];
		}
	}
	//printf("numtri=%d\n",numtri);
}

ull solve() {
	REP(i,n) sort(adj[i].begin(),adj[i].end());
	ull ret=0; //ull chk=0;
	// none
	REP(i,n) {
		int nlarger=n-i-1,nsmaller=i;
		ull na=(ll)nlarger*(nlarger-1)/2,nb=(ll)nsmaller*nlarger,nc=(ll)nsmaller*(nsmaller-1)/2;
		ret+=(na*A+nb*B+nc*C)*((ull)i);
	}
	//{ REP(a,n) FOR(b,a+1,n) FOR(c,b+1,n) chk+=((ull)A*a)+((ull)B*b)+((ull)C*c); printf("ret=%llu chk=%llu\n",ret,chk); }
	// AB
	REP(a,n) REPSZ(i,adj[a]) {
		int b=adj[a][i]; if(!(a<b)) continue;
		int nlarger=n-b-1;
		ull nc=nlarger,csum=(ll)(b+1+n-1)*nlarger/2;
		ret-=nc*((ull)a*A+(ull)b*B)+csum*C;
	}
	//{ REP(a,n) FOR(b,a+1,n) FOR(c,b+1,n) if(exists(a,b)) chk-=((ull)A*a)+((ull)B*b)+((ull)C*c); printf("ret=%llu chk=%llu\n",ret,chk); }
	// BC
	REP(b,n) REPSZ(i,adj[b]) {
		int c=adj[b][i]; if(!(b<c)) continue;
		int nsmaller=b;
		ull na=nsmaller,asum=(ll)(0+b-1)*nsmaller/2;
		ret-=na*((ull)b*B+(ull)c*C)+asum*A;
	}
	//{ REP(a,n) FOR(b,a+1,n) FOR(c,b+1,n) if(exists(b,c)) chk-=((ull)A*a)+((ull)B*b)+((ull)C*c); printf("ret=%llu chk=%llu\n",ret,chk); }
	// AC
	REP(a,n) REPSZ(i,adj[a]) {
		int c=adj[a][i]; if(!(a<c)) continue;
		int nbetween=c-a-1;
		ull nb=nbetween,bsum=(ll)(a+1+c-1)*nbetween/2;
		ret-=nb*((ull)a*A+(ull)c*C)+bsum*B;
	}
	//{ REP(a,n) FOR(b,a+1,n) FOR(c,b+1,n) if(exists(a,c)) chk-=((ull)A*a)+((ull)B*b)+((ull)C*c); printf("ret=%llu chk=%llu\n",ret,chk); }
	// AB+BC
	REP(b,n) {
		int nsmaller=0,nlarger=0; REPSZ(i,adj[b]) if(adj[b][i]<b) ++nsmaller; else if(adj[b][i]>b) ++nlarger;
		REPSZ(i,adj[b]) { int a=adj[b][i]; if(!(a<b)) continue; ull nc=nlarger; ret+=nc*((ull)a*A); }
		{ ll na=nsmaller,nc=nlarger; ret+=na*nc*((ull)b*B); }
		REPSZ(i,adj[b]) { int c=adj[b][i]; if(!(b<c)) continue; ull na=nsmaller; ret+=na*((ull)c*C); }
	}
	//{ REP(a,n) FOR(b,a+1,n) FOR(c,b+1,n) if(exists(a,b)&&exists(b,c)) chk+=((ull)A*a)+((ull)B*b)+((ull)C*c); printf("ret=%llu chk=%llu\n",ret,chk); }
	// AB+AC
	REP(a,n) {
		int nlarger=0,sofar=0; REPSZ(i,adj[a]) if(adj[a][i]>a) ++nlarger;
		{ ll nbc=(ll)nlarger*(nlarger-1)/2; ret+=nbc*((ull)a*A); }
		REPSZ(i,adj[a]) {
			int x=adj[a][i]; if(!(a<x)) continue;
			int nbefore=sofar,nafter=nlarger-nbefore-1;
			ull nb=nbefore,nc=nafter;
			ret+=nc*((ull)x*B)+nb*((ull)x*C);
			++sofar;
		}
	}
	//{ REP(a,n) FOR(b,a+1,n) FOR(c,b+1,n) if(exists(a,b)&&exists(a,c)) chk+=((ull)A*a)+((ull)B*b)+((ull)C*c); printf("ret=%llu chk=%llu\n",ret,chk); }
	// BC+AC
	REP(c,n) {
		int nsmaller=0,sofar=0; REPSZ(i,adj[c]) if(adj[c][i]<c) ++nsmaller;
		REPSZ(i,adj[c]) {
			int x=adj[c][i]; if(!(x<c)) continue;
			int nbefore=sofar,nafter=nsmaller-nbefore-1;
			ull na=nbefore,nb=nafter;
			ret+=nb*((ull)x*A)+na*((ull)x*B);
			++sofar;
		}
		{ ull nab=(ll)nsmaller*(nsmaller-1)/2; ret+=nab*((ull)c*C); }
	}
	//{ REP(a,n) FOR(b,a+1,n) FOR(c,b+1,n) if(exists(b,c)&&exists(a,c)) chk+=((ull)A*a)+((ull)B*b)+((ull)C*c); printf("ret=%llu chk=%llu\n",ret,chk); }
	// AB+BC+AC
	counttriangles();
	REP(a,n) ret-=((ull)ntrilo[a])*((ull)a*A);
	REP(b,n) ret-=((ull)ntrimi[b])*((ull)b*B);
	REP(c,n) ret-=((ull)ntrihi[c])*((ull)c*C);
	//{ REP(a,n) FOR(b,a+1,n) FOR(c,b+1,n) if(exists(a,b)&&exists(b,c)&&exists(a,c)) chk-=((ull)A*a)+((ull)B*b)+((ull)C*c); printf("ret=%llu chk=%llu\n",ret,chk); }
	return ret;
}

void run() {
	scanf("%d%d",&n,&m); scanf("%llu%llu%llu",&A,&B,&C); REP(i,m) { int a,b; scanf("%d%d",&a,&b); adj[a].PB(b); adj[b].PB(a); }
	printf("%llu\n",solve());
}

void stress() {
	n=MAXN; A=rand()%1000*1000+rand()%1000+1; B=rand()%1000*1000+rand()%1000+1; C=rand()%1000*1000+rand()%1000+1;
	//REP(i,MAXM) { int a=(rand()%1000*1000+rand()%1000)%n,b=(rand()%1000*1000+rand()%1000)%n; if(a!=b) adj[a].PB(b),adj[b].PB(a); }
	int nx=0; while((nx+2)*(nx+1)/2<=MAXM) ++nx; REP(i,nx) FOR(j,i+1,nx) adj[i].PB(j),adj[j].PB(i);
	printf("%llu\n",solve());
}

int main() {
	run();
	//stress();
	return 0;
}