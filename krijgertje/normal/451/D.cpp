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

char s[100001]; int n;

ll cnt[2][2];

void run() {
	scanf("%s",s); n=strlen(s);
	memset(cnt,0,sizeof(cnt));
	REP(i,n) ++cnt[s[i]-'a'][i%2];
	ll even=0,odd=0;
	REP(i,2) even+=cnt[i][0]*cnt[i][1];
	REP(i,2) REP(j,2) odd+=cnt[i][j]*(cnt[i][j]+1)/2;
	cout<<even<<" "<<odd<<endl;
}


int main() {
	run();
	return 0;
}