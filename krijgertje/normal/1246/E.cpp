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
#include <random>
#include <bitset>
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

const int MAXN=16;
const int MAXSUM=2000;
typedef bitset<MAXSUM+1> bs;

int n,base;
int a[MAXN];
vector<pair<int,int>> ans;

bs can[1<<MAXN];

int cnt[MAXN];
bool done[MAXN];

void reconstruct() {
	int mask=(1<<n)-1,val=1; assert(can[mask][val]);
	REP(i,n) cnt[i]=0,done[i]=false;
	while(mask!=0) {
		while(val*base<=MAXSUM&&can[mask][val*base]) {
			REP(i,n) if(!done[i]) ++cnt[i];
			val*=base;
		}
		bool found=false;
		REP(i,n) if((mask&(1<<i))!=0&&a[i]<=val&&can[mask-(1<<i)][val-a[i]]) {
			mask-=1<<i;
			val-=a[i];
			done[i]=true;
			found=true;
			break;
		}
		assert(found);
	}
	assert(val==0);
	//REP(i,n) printf("%d: cnt=%d\n",i,cnt[i]);
	ans.clear();
	vector<pair<int,int>> rem; REP(i,n) rem.PB(MP(a[i],cnt[i]));
	while(SZ(rem)>=2) {
		int mx=-1; REPSZ(i,rem) mx=max(mx,rem[i].second);
		int x=-1,y=-1; REPSZ(i,rem) if(rem[i].second==mx) { if(x==-1) x=i; else if(y==-1) y=i; } assert(x!=-1&&y!=-1);
		ans.PB(MP(rem[x].first,rem[y].first));
		vector<pair<int,int>> nrem; REPSZ(i,rem) if(i!=x&&i!=y) nrem.PB(rem[i]);
		int sum=rem[x].first+rem[y].first; while(sum%base==0) sum/=base,--mx; nrem.PB(MP(sum,mx));
		rem=nrem;
	}
}

bool solve() {
	REP(mask,1<<n) can[mask].reset();
	can[0].set(0);
	REP(mask,1<<n) {
		for(int i=MAXSUM;i>=0;--i) if(i%base==0&&can[mask][i]) can[mask][i/base]=true;
		REP(i,n) if((mask&(1<<i))==0) can[mask|(1<<i)]|=can[mask]<<a[i];
	}
	if(!can[(1<<n)-1][1]) return false;
	reconstruct();
	return true;
}

void run() {
	scanf("%d%d",&n,&base);
	REP(i,n) scanf("%d",&a[i]);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	REPSZ(i,ans) printf("%d %d\n",ans[i].first,ans[i].second);
}

int main() {
	run();
	return 0;
}