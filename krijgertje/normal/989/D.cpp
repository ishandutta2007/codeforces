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

int len,wmax;

ll solve(vector<pair<int,int> > cloud) {
	if(wmax==1) return 0;
	vector<int> l,r;
	REPSZ(i,cloud) if(cloud[i].second==-1) l.PB(cloud[i].first+len); else if(cloud[i].second==+1) r.PB(cloud[i].first);
	sort(l.begin(),l.end()); sort(r.begin(),r.end());
	//printf("l:"); REPSZ(i,l) printf(" %d",l[i]); puts("");
	//printf("r:"); REPSZ(i,r) printf(" %d",r[i]); puts("");
	ll ret=0;
	int j=0;
	REPSZ(i,r) {
		// r[i]/(wmax-1) < l[j]/(wmax+1) -> l[j]>r[i]*(wmax+1)/(wmax-1)
		while(j<SZ(l)&&(ll)(wmax-1)*l[j]<=(ll)r[i]*(wmax+1)) ++j;
		ret+=SZ(l)-j;
	}
	return ret;
}

int n;
int x[MAXN],v[MAXN];

void run() {
	scanf("%d%d%d",&n,&len,&wmax);
	REP(i,n) scanf("%d%d",&x[i],&v[i]);

	int mcloud=0;
	vector<pair<int,int> > lcloud;
	vector<pair<int,int> > rcloud;
	REP(i,n) {
		if(x[i]>=0) {
			rcloud.PB(MP(x[i],v[i]));
		} else if(x[i]+len<=0) {
			lcloud.PB(MP(-(x[i]+len),-v[i]));
		} else {
			mcloud=v[i];
		}
	}

	int lneg=0,rneg=0; REPSZ(i,lcloud) if(lcloud[i].second<0) ++lneg; REPSZ(i,rcloud) if(rcloud[i].second<0) ++rneg;
	ll ret=(ll)lneg*rneg;
	if(mcloud==-1) ret+=lneg;
	if(mcloud==+1) ret+=rneg;
	ret+=solve(lcloud);
	ret+=solve(rcloud);
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}