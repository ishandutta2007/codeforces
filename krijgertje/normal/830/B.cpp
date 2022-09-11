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

int n;
int a[MAXN];
pair<int,int> o[MAXN];

int bit[MAXN+1];
int bget(int idx) { ++idx; int ret=0; while(idx>0) { ret+=bit[idx]; idx-=idx&-idx; } return ret; }
void bmod(int idx,int by) { ++idx; while(idx<=n) { bit[idx]+=by; idx+=idx&-idx; } }


void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	REP(i,n) o[i]=MP(a[i],i);
	sort(o,o+n);
	memset(bit,0,sizeof(bit));
	REP(i,n) bmod(i,+1);
	int pos=0;
	ll ret=0;
	for(int at=0,to=at;at<n;at=to) {
		while(to<n&&o[at].first==o[to].first) ++to;
		int v=o[at].first,cnt=to-at;
		int fst=lower_bound(o+at,o+to,MP(v,pos))-o-at; if(fst==cnt) fst=0;
		REP(i,cnt) {
			int now=o[at+(fst+i)%cnt].second;
			int cur;
			if(now>=pos) {
				cur=bget(now)-bget(pos-1);
			} else {
				cur=bget(n-1)-bget(pos-1)+bget(now);
			}
			//printf("now=%d cur=%d\n",now,cur);
			ret+=cur;
			bmod(now,-1);
			pos=now;
		}
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}