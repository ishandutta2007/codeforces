#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <climits>
#include <cassert>
#include <ctime>
#include <cstring>
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
ll gcd(ll u, ll v) { while ( v != 0) { ll r = u % v; u = v; v = r; } return u; }

ll n,k,d2,d3;

bool can() {
	if(n%3!=0) return false;
	ll want=n/3;
	{ // a>b, a>c
		ll a=max(d2,d3),b=a-d2,c=a-d3;
		if(a+b+c<=k&&(k-a-b-c)%3==0&&max(a,max(b,c))+(k-a-b-c)/3<=want) return true;
	}
	{ // a>b, c>a
		ll c=d2+d3,a=c-d3,b=a-d2;
		if(a+b+c<=k&&(k-a-b-c)%3==0&&max(a,max(b,c))+(k-a-b-c)/3<=want) return true;
	}
	{ // b>a, a>c
		ll b=d2+d3,a=b-d2,c=a-d3;
		if(a+b+c<=k&&(k-a-b-c)%3==0&&max(a,max(b,c))+(k-a-b-c)/3<=want) return true;
	}
	{ // b>a, c>a
		ll a=0,b=a+d2,c=a+d3;
		if(a+b+c<=k&&(k-a-b-c)%3==0&&max(a,max(b,c))+(k-a-b-c)/3<=want) return true;
	}
	return false;
}

void run() {
	cin>>n>>k>>d2>>d3;
	printf("%s\n",can()?"yes":"no");
}

void gen() {
	int cnt=0;
	FORE(n,1,30) REPE(k,n) REPE(d2,k) REPE(d3,k) ++cnt;
	cout<<cnt<<endl;
	FORE(n,1,30) REPE(k,n) REPE(d2,k) REPE(d3,k) printf("%d %d %d %d\n",n,k,d2,d3);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	//gen();
	return 0;
}