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

int n;
int a[2000000];

void run(int casenr) {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);
	sort(a,a+n);
	ll sum=0;
	for(int cnt=1;cnt<=n;cnt*=4) {
		REP(i,cnt) sum+=a[n-i-1];
	}
	cout<<sum<<endl;
}

int main() {
	//int n; scanf("%d",&n); FORE(i,1,n) run(i);
	run(1);
	return 0;
}