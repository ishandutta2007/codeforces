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

const int MAXN=150000;

int n;
int a[MAXN];
int b[MAXN];

int o[MAXN];
bool cmp(const int &i,const int &j) { if(b[i]!=b[j]) return b[i]<b[j]; if(a[i]!=a[j]) return a[i]<a[j]; return i<j; }


int prv[MAXN],nprv;
int cur[MAXN],ncur;
int nxt[MAXN],nnxt;

bool alive[MAXN];
ll res[MAXN];
ll ret[MAXN]; int nret;


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	REP(i,n) { b[i]=a[i]; while(b[i]%2==0) b[i]/=2; }
	REP(i,n) o[i]=i; sort(o,o+n,cmp);
	//printf("o:"); REP(i,n) printf(" %d",o[i]); puts("");

	REP(i,n) alive[i]=false;
	for(int l=0,r=l;l<n;l=r) {
		while(r<n&&b[o[l]]==b[o[r]]) ++r;
		nprv=0; ll val=a[o[l]]; int at=l;
		while(nprv>0||at<r) {
			ncur=0; while(at<r&&a[o[at]]==val) cur[ncur++]=o[at++];
			nnxt=0; int atprv=0,atcur=0;
			while(atprv<nprv||atcur<ncur) {
				int u=-1; if(atprv<nprv&&(atcur>=ncur||prv[atprv]<cur[atcur])) u=prv[atprv++]; else u=cur[atcur++]; assert(u!=-1);
				if(atprv>=nprv&&atcur>=ncur) { alive[u]=true; res[u]=val; break; }
				int v=-1; if(atprv<nprv&&(atcur>=ncur||prv[atprv]<cur[atcur])) v=prv[atprv++]; else v=cur[atcur++]; assert(v!=-1);
				nxt[nnxt++]=v;
			}
			nprv=nnxt; REP(i,nnxt) prv[i]=nxt[i]; val*=2;
		}
	}
	nret=0; REP(i,n) if(alive[i]) ret[nret++]=res[i];
	printf("%d\n",nret); REP(i,nret) { if(i!=0) printf(" "); printf("%lld",ret[i]); } puts("");
}

int main() {
	run();
	return 0;
}