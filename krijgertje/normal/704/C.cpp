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

const int MOD=1000000007;
const int MAXC=100000;
const int MAXV=100000;

int nc,nv;
int ccnt[MAXV];
int c[MAXV][2]; // var->clause
int vcnt[MAXC];
int v[MAXC][2]; bool vpos[MAXC][2]; // clause->var

bool done[MAXC];

void process(int sat,int sme,int ret[2]) {
	// cur[x][y][z] = ways to make xor of currently considered clauses y, given that me has value z, we still need to consider at, and sme has value x
	int at=sat,me=sme,cur[2][2][2],ncur[2][2][2]; memset(cur,0,sizeof(cur));
	cur[0][0][0]=ret[0],cur[0][1][0]=ret[1]; if(sme!=-1) cur[1][0][1]=ret[0],cur[1][1][1]=ret[1];
	//printf("processing(%d) sme=%d\n",sat,sme+1);
	while(true) {
		//printf("\tat %d, me=%d\n",at,me+1);
		done[at]=true;
		int other=-1; bool mepos=true,otherpos,hadme=false; REP(j,vcnt[at]) if(v[at][j]==me&&!hadme) mepos=vpos[at][j],hadme=true; else if(other==-1) other=v[at][j],otherpos=vpos[at][j];
		//printf("\tother %d\n",other+1);
		if(other==-1) {
			ret[0]=ret[1]=0;
			REP(x,2) REP(y,2) REP(z,2) { int ny=y^(mepos?z:1-z); if((ret[ny]+=cur[x][y][z])>=MOD) ret[ny]-=MOD; }
			break;
		} else {
			//printf("\t\t"); REP(x,2) REP(y,2) REP(z,2) printf("%d ",cur[x][y][z]); puts("");
			memset(ncur,0,sizeof(ncur));
			REP(x,2) REP(y,2) REP(z,2) REP(nz,2) if(cur[x][y][z]>0) {
				int ny=y^((mepos?z:1-z)|(otherpos?nz:1-nz));
				//printf("\t\t%d %c%d %c%d -> %d\n",y,mepos?'+':'-',z,otherpos?'+':'-',nz,ny);
				if((ncur[x][ny][nz]+=cur[x][y][z])>=MOD) ncur[x][ny][nz]-=MOD;
			}
			REP(x,2) REP(y,2) REP(z,2) cur[x][y][z]=ncur[x][y][z];
			//printf("\t\t"); REP(x,2) REP(y,2) REP(z,2) printf("%d ",cur[x][y][z]); puts("");
			me=other;
			int to=-1; bool hadat=false; REP(j,ccnt[me]) if(c[me][j]==at&&!hadat) hadat=true; else { to=c[me][j]; break; }
			if(to==-1||me==sme) {
				//printf("to=%d\n",to);
				ret[0]=ret[1]=0;
				REP(x,2) REP(y,2) REP(z,2) if(to==-1||x==z) { if((ret[y]+=cur[x][y][z])>=MOD) ret[y]-=MOD; }
				break;
			} else {
				at=to;
			}
		}
	}
	//printf("->%d %d\n",ret[0],ret[1]);
}

void input() {
	scanf("%d%d",&nc,&nv);
	REP(i,nc) { scanf("%d",&vcnt[i]); REP(j,vcnt[i]) { int x; scanf("%d",&x); v[i][j]=abs(x)-1; vpos[i][j]=x>0; } }
}

int solve() {
	memset(ccnt,0,sizeof(ccnt)); REP(i,nc) REP(j,vcnt[i]) c[v[i][j]][ccnt[v[i][j]]++]=i;

	memset(done,false,sizeof(done));
	int ret[2]; ret[0]=1,ret[1]=0;
	REP(i,nv) if(ccnt[i]==0) REP(y,2) ret[y]=(ll)2*ret[y]%MOD;
	REP(i,nc) if(vcnt[i]==1&&!done[i]) process(i,-1,ret);
	REP(i,nc) if(vcnt[i]==2) REP(j,vcnt[i]) if(ccnt[v[i][j]]==1&&!done[i]) process(i,v[i][j],ret);
	REP(i,nc) if(vcnt[i]==2&&!done[i]) process(i,v[i][0],ret);
	return ret[1];
}

void run() {
	input();
	printf("%d\n",solve());
}

int pv[MAXV],pc[MAXC];
void addcycle(int n) {
	REP(i,n) pv[i]=nv+i,pc[i]=nc+i; random_shuffle(pv,pv+n); random_shuffle(pc,pc+n);
	REP(ii,n) { int i=pc[ii]; vcnt[i]=2; REP(j,2) { v[i][j]=pv[(i+j)%n]; vpos[i][j]=rand()%2==0; } }
	nc+=n; nv+=n;
}
void addpath(int n) {
	bool a=rand()%2==0,b=rand()%2==0; int nn=n-1+(a?1:0)+(b?1:0);
	REP(i,n) pc[i]=nc+i; REP(i,nn) pv[i]=nv+i; random_shuffle(pc,pc+n); random_shuffle(pv,pv+nn);
	REP(ii,n) {
		int i=pc[ii]; vcnt[i]=0;
		if(ii==0&&a) { v[i][vcnt[i]]=pv[--nn]; vpos[i][vcnt[i]]=rand()%2==0; ++vcnt[i]; }
		if(ii-1>=0) { v[i][vcnt[i]]=pv[ii-1]; vpos[i][vcnt[i]]=rand()%2==0; ++vcnt[i]; }
		if(ii+1<n) { v[i][vcnt[i]]=pv[ii]; vpos[i][vcnt[i]]=rand()%2==0; ++vcnt[i]; }
		if(ii+1==n&&b) { v[i][vcnt[i]]=pv[--nn]; vpos[i][vcnt[i]]=rand()%2==0; ++vcnt[i]; }
	}
	nc+=n; nv+=n-1+(a?1:0)+(b?1:0);
}

int bf() {
	int ret=0;
	REP(i,1<<nv) {
		int cur=0;
		REP(j,nc) { int now=0; REP(k,vcnt[j]) { int x=(i>>v[j][k])&1; if(!vpos[j][k]) x=1-x; if(x==1) now=1; } cur^=now; }
		if(cur==1) ++ret;
	}
	return ret;
}

void test() {
	srand(time(NULL));
	nc=0,nv=0;
	addcycle(10);
	//addpath(10);
	printf("%d %d\n",nc,nv);
	REP(i,nc) { printf("%d",vcnt[i]); REP(j,vcnt[i]) { printf(" "); if(!vpos[i][j]) printf("-"); printf("%d",v[i][j]+1); } puts(""); }
	printf("-> %d (want %d)\n",solve(),bf());
}

int main() {
	//test();
	run();
	return 0;
}