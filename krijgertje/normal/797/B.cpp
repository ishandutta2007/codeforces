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
int x[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]);
	ll sum=0; int nodd=0; int minposodd=0; int maxnegodd=0;
	REP(i,n) {
		if(x[i]>=0) {
			sum+=x[i];
			if(x[i]%2==1) {
				++nodd;
				if(minposodd==0||x[i]<minposodd) minposodd=x[i];
			}
		} else if(x[i]%2!=0&&(maxnegodd==0||x[i]>maxnegodd)) {
			maxnegodd=x[i];
			//printf("maxnegodd -> %d\n",x[i]);
		}
	}
	if(nodd==0) sum+=maxnegodd;
	else if(nodd%2==0) sum-=maxnegodd==0?minposodd:min(-maxnegodd,minposodd);
	printf("%lld\n",sum);
}

int main() {
	run();
	return 0;
}