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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n;
int a[100000];
int cnt[100000];

void run() {
	scanf("%d",&n); REP(i,n) { scanf("%d",&a[i]); --a[i]; }

	int sur=0,me=0,mid=0,other=0;
	REP(i,n) cnt[i]=0;
	while(me+other<n) {
		if(cnt[a[n-other-1]]>0) { --cnt[a[n-other-1]]; ++other; continue; }
		cnt[a[me]]++; ++me;
	}
	if(me==other+1&&cnt[a[me-1]]>0) cnt[a[me-1]]--,--me,++mid;
	if(me==other) while(me>0&&a[me-1]==a[n-me]) --me,--other,mid+=2;
	while(me>0&&a[sur]==a[n-sur-1]) ++sur,--me,--other;
	//printf("%d-%d-%d-%d-%d\n",sur,me,mid,other,sur);

	ll ret=0;
	if(mid==n) {
		ret+=(ll)n*(n+1)/2;
	} else if(me==other) {
		ret+=(ll)(sur+1)*(mid+other+sur+1);
		ret+=(ll)(sur+me+mid+1)*(sur+1);
		ret-=(ll)(sur+1)*(sur+1);
	} else {
		int nodd=0; REP(i,n) if(cnt[i]%2!=0) ++nodd;
		if(nodd<=n%2) {
			int sur2=0,me2=0,mid2=0,other2=0;
			REP(i,n) cnt[i]=0;
			while(me2+other2<n) {
				if(cnt[a[other2]]>0) { --cnt[a[other2]]; ++other2; continue; }
				cnt[a[n-me2-1]]++; ++me2;
			}
			if(me2==other2+1) cnt[a[n-me2]]--,--me2,++mid2;
			if(me2==other2) while(me2>0&&a[me2-1]==a[n-me2]) --me2,--other2,mid2+=2;
			while(me2>0&&a[sur2]==a[n-sur2-1]) ++sur2,--me2,--other2;
			//printf("%d-%d-%d-%d-%d\n",sur2,other2,mid2,me2,sur2);
			assert(mid==0&&mid2==0&&sur==sur2&&me+other==other2+me2);
			ret+=(ll)(sur+1)*(other+sur+1);
			ret+=(ll)(sur+other2+1)*(sur+1);
			ret-=(ll)(sur+1)*(sur+1);
		}
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}