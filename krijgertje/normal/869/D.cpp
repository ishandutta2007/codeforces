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

const int MAXE=4;
const int MOD=1000000007;

int n,ne;
int e[MAXE][2];

int use[MAXE],nuse;
int perm[MAXE];

int path[MAXE][2],npath;
set<int> been;

int countdesc(int a) {
	int ret=0;
	int la=a,ha=a;
	while(la<=n) {
		ret+=ha-la+1;
		la=la*2,ha=min(n,ha*2+1);
	}
	return ret;
}

int calcways(int a,int b) {
	int ret=0;

	map<int,vector<pair<set<int>,int> > > forbidden;
	for(auto it=been.begin();it!=been.end();++it) {
		set<int> cur;
		for(int at=*it/2;at!=0;at/=2) {
			forbidden[at].PB(MP(cur,*it));
			if(been.count(at)) break;
			cur.insert(at);
		}
	}
	//for(auto it=forbidden.begin();it!=forbidden.end();++it) { printf("%d:",it->first); REPSZ(i,it->second) { printf(" %d unless",it->second[i].second); for(auto it2=it->second[i].first.begin();it2!=it->second[i].first.end();++it2) printf("%c%d",it2==it->second[i].first.begin()?' ':',',*it2); } puts(""); }

	for(int sa=a,pa=-1;sa!=0;pa=sa,sa/=2) {
		if(sa!=a) { if(been.count(sa)) break; been.insert(sa); }
		for(int sb=b,pb=-1;sb!=0;pb=sb,sb/=2) {
			if(sb!=b) { if(been.count(sb)) break; }
			int na=0,nb=0,cura=sa,curb=sb; bool aok=true,bok=true;
			if(pa!=-1) { ++na; cura=pa^1; aok=!been.count(cura)&&cura!=sb&&cura<=n; }
			if(pb!=-1) { ++nb; curb=pb^1; bok=!been.count(curb)&&curb<=n; }
			bool sbforbidden=false,saforbidden=false;
			if(sb!=b) for(int c=sb/2;c!=0;c/=2) if(c==cura) { sbforbidden=true; break; } else if(been.count(c)) break;
			if(sa!=a) for(int c=sa/2;c!=0;c/=2) if(c==curb) { saforbidden=true; break; } else if(been.count(c)) break;
			if(aok) {
				na+=countdesc(cura);
				if(forbidden.count(cura)) { vector<pair<set<int>,int> > v=forbidden[cura]; REPSZ(i,v) if(!v[i].first.count(sb)) na-=countdesc(v[i].second); }
				if(sbforbidden) na-=countdesc(sb);
			}
			if(bok) {
				nb+=countdesc(curb);
				if(forbidden.count(curb)) { vector<pair<set<int>,int> > v=forbidden[curb]; REPSZ(i,v) if(!v[i].first.count(sa)) nb-=countdesc(v[i].second); }
				if(saforbidden) nb-=countdesc(sa);
			}
			//printf("\tsa=%d sb=%d -> %d*%d [cur=%d,%d]\n",sa,sb,na,nb,cura,curb);
			ret=(ret+(ll)na*nb)%MOD;
		}
	}
	return ret;
}

int calcpath() {
	been.clear();
	if(!been.insert(path[0][0]).second) return 0;
	if(!been.insert(path[npath-1][1]).second) return 0;
	REP(i,npath-1) {
		int a=path[i][1],b=path[i+1][0];
		while(a!=b) {
			if(a<b) swap(a,b);
			if(!been.insert(a).second) return 0;
			a=a/2;
		}
		if(!been.insert(a).second) return 0;
	}
	int ret=calcways(path[0][0],path[npath-1][1]);
	//REP(i,npath) printf("%d-%d ",path[i][0],path[i][1]); printf("= %d\n",ret);
	return ret;
}

int solve() {
	int ret=(ll)n*n%MOD;
	FOR(mask,1,1<<ne) {
		nuse=0; REP(i,ne) if(mask&(1<<i)) use[nuse++]=i;
		REP(i,nuse) perm[i]=i;
		do {
			REP(rev,1<<nuse) {
				npath=nuse; REP(i,nuse) { path[i][0]=e[use[perm[i]]][0],path[i][1]=e[use[perm[i]]][1]; if(rev&(1<<i)) swap(path[i][0],path[i][1]); }
				ret=(ret+calcpath())%MOD;
			}
		} while(next_permutation(perm,perm+nuse));
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&ne);
	REP(i,ne) scanf("%d%d",&e[i][0],&e[i][1]);
	printf("%d\n",solve());
}


vector<bool> bfbeen;
int bfrec(int at) {
	if(bfbeen[at]) return 0; else bfbeen[at]=true; int ret=1;
	if(at!=1) ret+=bfrec(at/2);
	if(2*at<=n) ret+=bfrec(2*at);
	if(2*at+1<=n) ret+=bfrec(2*at+1);
	REP(i,ne) REP(j,2) if(at==e[i][j]) ret+=bfrec(e[i][1-j]);
	bfbeen[at]=false; return ret;
}
int bf() {
	bfbeen=vector<bool>(n+1,false);
	int ret=0;
	FORE(i,1,n) ret+=bfrec(i);
	return ret;
}

void stress() {
	REP(rep,1000) {
		n=20; ne=4;
		REP(i,ne) while(true) { REP(j,2) e[i][j]=rand()%n+1; if(e[i][0]!=e[i][1]) break; }
		int have=solve(),want=bf();
		if(have!=want) {
			printf("have=%d want=%d\n",have,want);
			printf("%d %d ",n,ne); REP(i,ne) printf(" %d %d",e[i][0],e[i][1]); puts("");
		} else printf(".");
	}
}

int main() {
	run();
	//stress();
	return 0;
}