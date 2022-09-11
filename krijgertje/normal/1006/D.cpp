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
#include <cstring>
#include <list>  
#include <cassert>
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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n;
char a[MAXN+1],b[MAXN+1];

void run() {
	scanf("%d%s%s",&n,a,b);
	int ret=0;
	for(int i=0;i<=n-i-1;++i) {
		if(i==n-i-1) {
			if(a[i]!=b[i]) ++ret;
		} else {
			char cur[4]; cur[0]=a[i],cur[1]=a[n-i-1],cur[2]=b[i],cur[3]=b[n-i-1]; sort(cur,cur+4);
			if(cur[0]==cur[1]&&cur[2]==cur[3]) continue;
			if(cur[0]!=cur[1]&&cur[1]!=cur[2]&&cur[2]!=cur[3]||a[i]==a[n-i-1]&&cur[0]!=cur[2]&&cur[1]!=cur[3]) ret+=2; else ++ret;
		}
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}