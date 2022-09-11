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

int n,slices;
int cnt[MAXN],a[MAXN],b[MAXN];

ll calc(pair<int,int> *lst,int nlst,ll amount) {
	ll left=amount,ret=0;
	sort(lst,lst+nlst);
	REP(i,nlst) {
		ll cur=min(left,(ll)lst[i].second);
		ret+=cur*lst[i].first; left-=cur;
	}
	//printf("calc=%lld\n",ret);
	return ret;
}

pair<int,int> atob[MAXN]; int natob;
pair<int,int> btoa[MAXN]; int nbtoa;

void run() {
	scanf("%d%d",&n,&slices);
	REP(i,n) scanf("%d%d%d",&cnt[i],&a[i],&b[i]);
	ll asum=0,bsum=0; natob=nbtoa=0; ll ret=0;
	REP(i,n) if(a[i]>=b[i]) { asum+=cnt[i]; ret+=(ll)a[i]*cnt[i]; atob[natob++]=MP(a[i]-b[i],cnt[i]); } else { bsum+=cnt[i]; ret+=(ll)b[i]*cnt[i]; btoa[nbtoa++]=MP(b[i]-a[i],cnt[i]); }
	ll sum=asum+bsum; ll need=(sum+slices-1)/slices;
	ll have=(asum+slices-1)/slices+(bsum+slices-1)/slices;
	if(have!=need) ret-=min(calc(atob,natob,asum%slices),calc(btoa,nbtoa,bsum%slices));
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}