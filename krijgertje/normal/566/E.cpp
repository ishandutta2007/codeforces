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

const int MAXN=1000;
const int MAXM=MAXN-1;
const int MAXLL=(MAXN+63)/64;
typedef struct BM {
	ull bits[MAXLL];
	void set(int x) { bits[x/64]|=1ULL<<(x%64); }
	bool isset(int x) { return ((bits[x/64]>>(x%64))&1)!=0; }
	bool getonly2(int &a,int &b) {
		int cnt=0;
		REP(i,MAXLL) {
			if(bits[i]==0) continue;
			REP(j,64) if(((bits[i]>>j)&1)!=0) { if(cnt==0) a=i*64+j; else if(cnt==1) b=i*64+j; else return false; ++cnt; }
		}
		return cnt==2;
	}
} BM;

BM intersect(const BM &a,const BM &b) {
	BM ret;
	REP(i,MAXLL) ret.bits[i]=a.bits[i]&b.bits[i];
	return ret;
}
bool equal(const BM &a,const BM &b) {
	REP(i,MAXLL) if(a.bits[i]!=b.bits[i]) return false;
	return true;
}

int n;
BM near[MAXN]; int nearcnt[MAXN];
BM intern;
BM adjintern[MAXN];

int ret[MAXM][2],nret;

void run() {
	scanf("%d",&n);
	memset(near,0,sizeof(near));
	memset(&intern,0,sizeof(intern));
	memset(adjintern,0,sizeof(adjintern));
	REP(i,n) {scanf("%d",&nearcnt[i]); REP(j,nearcnt[i]) { int x; scanf("%d",&x); --x; near[i].set(x); } }

	nret=0;
	REP(i,n) FOR(j,i+1,n) {
		BM cur=intersect(near[i],near[j]);
		int a,b; if(!cur.getonly2(a,b)) continue;
		intern.set(a); intern.set(b);
		if(adjintern[a].isset(b)) continue;
		adjintern[a].set(a); adjintern[a].set(b);
		adjintern[b].set(b); adjintern[b].set(a);
		//printf("\t(%d,%d) -> (%d,%d)\n",i,j,a,b);
		ret[nret][0]=a,ret[nret][1]=b,++nret;
	}

	int oret=nret;
	if(nret==0) { //star
		FOR(i,1,n) ret[nret][0]=0,ret[nret][1]=i,++nret;
	} else if(nret==1) { //dumbbell
		int fst=-1;
		REP(i,n) if(!intern.isset(i)) {
			if(fst==-1) fst=i;
			int cur=-1;
			REP(j,n) if(near[j].isset(i)&&(cur==-1||nearcnt[j]<nearcnt[cur])) cur=j;
			assert(cur!=-1);
			ret[nret][0]=near[cur].isset(fst)?ret[0][0]:ret[0][1],ret[nret][1]=i,++nret;
		}
	} else {
		REP(i,n) if(!intern.isset(i)) {
			int cur=-1;
			REP(j,n) if(near[j].isset(i)&&(cur==-1||nearcnt[j]<nearcnt[cur])) cur=j;
			assert(cur!=-1);
			BM nearintern=intersect(near[cur],intern);
			REP(j,n) if(intern.isset(j)&&equal(nearintern,adjintern[j])) {
				ret[nret][0]=i,ret[nret][1]=j,++nret;
			}
		}
	}

	REP(i,nret) printf("%d %d\n",ret[i][0]+1,ret[i][1]+1);
}

int main() {
	run();
	return 0;
}