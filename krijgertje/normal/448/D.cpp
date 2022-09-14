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

int X,Y; ll want;

void run() {
	cin>>X>>Y>>want;
	ll l=0,h=(ll)X*Y; // (l,h]
	while(l+1<h) {
		ll m=l+(h-l)/2;
		ll cnt=0; FORE(x,1,X) cnt+=min((ll)Y,m/x);
		//printf("%lld .. %lld: %lld -> %lld\n",l,h,m,cnt);
		if(cnt<want) l=m; else h=m;
	}
	cout<<h<<endl;
}

int main() {
	run();
	return 0;
}