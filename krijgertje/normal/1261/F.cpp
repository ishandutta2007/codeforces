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
#include <chrono>
#include <chrono>
#include <random>
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

const int MAXN=100;
const int MOD=998244353;
const int MAXBIT=59;
const int INV2=(MOD+1)/2;
void inc(int &a,int b) { if((a+=b)>=MOD) a-=MOD; }
struct Node { int c[2]; bool all; Node() { c[0]=c[1]=-1; all=false; } };

int na,nb;
ll al[MAXN],ar[MAXN];
ll bl[MAXN],br[MAXN];

vector<Node> nodes;
int makenode() { int ret=SZ(nodes); nodes.PB(Node()); return ret; }

int buildtree(int n,ll *l,ll *r) {
	int root=makenode();
	REP(i,n) {
		int lat=root,rat=root;
		for(int bit=MAXBIT;bit>=0;--bit) {
			int lbit=(l[i]>>bit)&1;
			int rbit=(r[i]>>bit)&1;
			if(lbit==0&&lat!=rat) { int oth=nodes[lat].c[1]; if(oth==-1) { oth=makenode(); nodes[lat].c[1]=oth; } nodes[oth].all=true; }
			if(rbit==1&&lat!=rat) { int oth=nodes[rat].c[0]; if(oth==-1) { oth=makenode(); nodes[rat].c[0]=oth; } nodes[oth].all=true; }
			int lto=nodes[lat].c[lbit]; if(lto==-1) { lto=makenode(); nodes[lat].c[lbit]=lto; }
			int rto=nodes[rat].c[rbit]; if(rto==-1) { rto=makenode(); nodes[rat].c[rbit]=rto; }
			lat=lto,rat=rto;
		}
		nodes[lat].all=nodes[rat].all=true;
	}
	return root;
}

vector<pair<ll,ll>> segs;
vector<pair<ll,int>> e;
vector<ll> eplus;
vector<ll> emin;

void gensegs(int lat,int rat,int bit,ll sofar) {
	//printf("lat=%d rat=%d bit=%d\n",lat,rat,bit);
	assert(bit>=-1);
	if(nodes[lat].all||nodes[rat].all) { ll l=sofar,r=sofar+(1LL<<(bit+1))-1; eplus.PB(l); emin.PB(r+1); return; }
	REP(lbit,2) REP(rbit,2) {
		int lto=nodes[lat].c[lbit],rto=nodes[rat].c[rbit];
		if(lto==-1||rto==-1) continue;
		gensegs(lto,rto,bit-1,sofar+((ll)(lbit^rbit)<<bit));
	}
}

int sum(ll a,ll b) {
	return ((b-a+1)%MOD)*((a+b)%MOD)%MOD*INV2%MOD;
}

int solve() {
	//REP(i,na) FORE(x,al[i],ar[i]) REP(j,nb) FORE(y,bl[j],br[j]) printf("%d\n",x^y);

	nodes.clear();
	int aroot=buildtree(na,al,ar);
	int broot=buildtree(nb,bl,br);

	segs.clear(); e.clear(); eplus.clear(); emin.clear();
	gensegs(aroot,broot,MAXBIT,0);
	//printf("segs:"); REPSZ(i,segs) printf(" [%lld..%lld]",segs[i].first,segs[i].second); puts("");

	//e.clear();
	//REPSZ(i,segs) { ll l=segs[i].first,r=segs[i].second; e.PB(MP(l,+1)); e.PB(MP(r+1,-1)); }
	//sort(e.begin(),e.end());
	sort(eplus.begin(),eplus.end());
	sort(emin.begin(),emin.end());

	int cnt=0; int ret=0; int plusat=0,minat=0; ll prv=-1;
	while(plusat<SZ(eplus)||minat<SZ(emin)) {
		ll cur=plusat<SZ(eplus)&&(minat>=SZ(emin)||eplus[plusat]<=emin[minat])?eplus[plusat]:emin[minat];
		if(cnt>0) { 
			//printf("can [%d..%d]\n",prv,cur-1); 
			inc(ret,sum(prv,cur-1));
		}
		while(plusat<SZ(eplus)&&eplus[plusat]==cur) ++cnt,++plusat;
		while(minat<SZ(emin)&&emin[minat]==cur) --cnt,++minat;
		prv=cur;
	}
	return ret;
}

void run() {
	scanf("%d",&na); REP(i,na) scanf("%lld%lld",&al[i],&ar[i]);
	scanf("%d",&nb); REP(i,nb) scanf("%lld%lld",&bl[i],&br[i]);
	printf("%d\n",solve());
}

void stress() {
	FORE(n,100,100) {
		na=n; REP(i,na) { al[i]=ar[i]=0; FORE(bit,40,MAXBIT) al[i]|=(ll)(rand()%2)<<bit,ar[i]|=(ll)(rand()%2)<<bit; if(al[i]>ar[i]) swap(al[i],ar[i]); ar[i]=al[i]+(1LL<<40); }
		nb=n; REP(i,nb) { bl[i]=br[i]=0; FORE(bit,40,MAXBIT) bl[i]|=(ll)(rand()%2)<<bit,br[i]|=(ll)(rand()%2)<<bit; if(bl[i]>br[i]) swap(bl[i],br[i]); br[i]=bl[i]+(1LL<<40); }
		solve();
		printf("%d: nodes=%d segs=%d e=%d\n",n,SZ(nodes),SZ(segs),SZ(eplus)+SZ(emin));
	}
}

int main() {
	run();
	//stress();
	return 0;
}