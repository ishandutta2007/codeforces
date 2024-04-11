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

int n,k;
bool fix[MAXN+1];
int a[MAXN+1];
char buff[20];

bool win() {
	int nfixed=0; REPE(i,n) if(fix[i]) ++nfixed;
	if(k==0) { if(fix[0]) return a[0]==0; else return nfixed%2==1; }
	if(nfixed<=n) return n%2==1;
	int have=0;
	REPE(i,n) {
		have+=a[i];
		if(have%k!=0) return false;
		have/=k;
	}
	return have==0;
}

void run() {
	scanf("%d%d",&n,&k);
	REPE(i,n) { scanf("%s",buff); if(strcmp(buff,"?")==0) fix[i]=false; else fix[i]=true,sscanf(buff,"%d",&a[i]); }
	printf("%s\n",win()?"Yes":"No");
}

int main() {
	run();
	return 0;
}