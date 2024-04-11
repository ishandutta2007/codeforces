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

ll gcd(ll a,ll b) { if(b==0) return a; return gcd(b,a%b); }

ll l,r;

void run() {
	cin>>l>>r;
	for(ll a=l;a<=r;++a) for(ll b=a+1;b<=r;++b) if(gcd(a,b)==1) for(ll c=b+1;c<=r;++c) if(gcd(b,c)==1&&gcd(a,c)!=1) { cout<<a<<" "<<b<<" "<<c<<endl; return; }
	printf("-1\n");
}

int main() {
	run();
	return 0;
}