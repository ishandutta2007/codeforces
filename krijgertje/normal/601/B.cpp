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

const int MAXN=100000;


int n,nq;
int x[MAXN];
pair<int,int> d[MAXN-1];

int uf[MAXN];
int find(int x) { if(uf[x]<0) return x; return uf[x]=find(uf[x]); }
void unite(int a,int b) { if(-uf[a]<-uf[b]) swap(a,b); uf[a]+=uf[b]; uf[b]=a; }

void run() {
	scanf("%d%d",&n,&nq);
	REP(i,n) scanf("%d",&x[i]);
	REP(i,n-1) d[i]=MP(abs(x[i+1]-x[i]),i); sort(d,d+n-1);

	REP(qi,nq) {
		int l,r; scanf("%d%d",&l,&r); --l,--r;
		ll ret=0;
		REP(i,n) uf[i]=-1;
		REP(i,n-1) {
			int a=d[i].second,b=d[i].second+1,val=d[i].first;
			if(a<l||b>r) continue;
			a=find(a),b=find(b);
			ret+=(ll)uf[a]*uf[b]*val;
			unite(a,b);			
		}
		printf("%I64d\n",ret);
	}

}


int main() {
	run();
	return 0;
}