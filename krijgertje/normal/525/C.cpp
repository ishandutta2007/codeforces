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
typedef long double ld;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

int n;
int x[100000];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&x[i]); sort(x,x+n); reverse(x,x+n);
	ll ret=0;
	int at1=0;
	while(at1+1<n) {
		if(x[at1]>x[at1+1]+1) { ++at1; continue; }
		int at2=at1+2;
		while(at2+1<n) {
			if(x[at2]>x[at2+1]+1) { ++at2; continue; }
			ret+=(ll)x[at1+1]*x[at2+1];
			break;
		}
		at1=at2+2;
	}
	cout<<ret<<endl;
}

int main() {
	run();
	return 0;
}