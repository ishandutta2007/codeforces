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

char s[500001]; int slen;
bool isvowel(char c) { return c=='I'||c=='E'||c=='A'||c=='O'||c=='U'||c=='Y'; }

void run() {
	scanf("%s",s); slen=strlen(s);

	double ret=0;
	int l=(slen+1)/2,h=slen-(slen-1)/2;
	double sum=0; int cnt=0;
	while(l>=1&&h<=slen) {
		sum+=1.0/l;
		if(l!=h) sum+=1.0/h;
		cnt+=isvowel(s[l-1]);
		if(l!=h) cnt+=isvowel(s[h-1]);
		//printf("%d..%d -> %lf (%d)\n",l,h,sum,cnt);
		ret+=sum*cnt;
		--l,++h;
	}
	printf("%.9lf\n",ret);
}

int main() {
	run();
	return 0;
}