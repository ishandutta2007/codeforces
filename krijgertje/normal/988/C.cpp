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

const int MAXSEQ=200000;
const int MAXLEN=200000;

int nseq;
int a[MAXLEN];

map<ll,pair<int,int> > mp;

void run() {
	scanf("%d",&nseq);
	REP(i,nseq) {
		int len; scanf("%d",&len); 
		REP(j,len) scanf("%d",&a[j]);
		ll sum=0; REP(j,len) sum+=a[j];
		REP(j,len) {
			ll cur=sum-a[j];
			if(mp.count(cur)) {
				pair<int,int> oth=mp[cur],me=MP(i,j);
				if(oth.first==me.first) continue;
				printf("YES\n%d %d\n%d %d\n",oth.first+1,oth.second+1,me.first+1,me.second+1);
				return;
			}
			mp[cur]=MP(i,j);
		}
	}
	printf("NO\n");
}

int main() {
	run();
	return 0;
}