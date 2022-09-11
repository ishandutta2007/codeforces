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

int a[MAXN];
void solve1(int n) {
	// 0..n-1 and 1..n
	int rem=n;
	while(rem>0) {
		int bit=0; while((2<<bit)<=rem) ++bit;
		int want=(2<<bit)-1;
		int orem=rem; while(want-(rem-1)<=orem) a[rem-1]=want-(rem-1),--rem;
	}
	//printf("a:"); REP(i,n) printf(" %d",a[i]); puts("");
	//vector<bool> have(n+1,false); REP(i,n) { if(a[i]<1||a[i]>n||have[a[i]]||(a[i]&i)!=0) printf("%d: err at %d: ai=%d, have=%s, and=%x\n",n,i,a[i],have[a[i]]?"yes":"no",a[i]&i); have[a[i]]=true; }
}

int ans1[MAXN];
int ans2[MAXN];

bool solve2(int n) {
	if(n<6) return false;
	ans2[0]=3,ans2[1]=6,ans2[2]=2,ans2[3]=5,ans2[4]=1,ans2[5]=4; int pos=5; bool skipped=false;
	FOR(i,6,n) {
		int val=i+1;
		if((val&(val-1))==0) { skipped=true; continue; }
		if(skipped) { skipped=false; ans2[i-1]=val; ans2[i]=val-1; pos=i; continue; }
		ans2[i]=ans2[pos]; ans2[pos]=val; pos=i;
	}
	return !skipped;
}

void run() {
	int n; scanf("%d",&n);

	if(n%2==1) {
		printf("NO\n");
	} else {
		solve1(n/2);
		REP(i,n/2) ans1[2*i]=2*a[i],ans1[2*a[i]-1]=2*i+1;
		//vector<bool> have(n+1,false); REP(i,n) { if(ans1[i]<1||ans1[i]>n||have[ans1[i]]||((i+1)&ans1[i])!=0) printf("err %d -> %d\n",i,a[i]); have[ans1[i]]=true; }
		printf("YES\n"); REP(i,n) { if(i!=0) printf(" "); printf("%d",ans1[i]); } puts("");
	}
	if(!solve2(n)) {
		printf("NO\n");
	} else {
		//vector<bool> have(n+1,false); REP(i,n) { if(ans2[i]<1||ans2[i]>n||have[ans2[i]]||((i+1)&ans2[i])==0) printf("err %d -> %d\n",i,a[i]); have[ans2[i]]=true; }
		printf("YES\n"); REP(i,n) { if(i!=0) printf(" "); printf("%d",ans2[i]); } puts("");
	}
}

int main() {
	run();
	return 0;
}