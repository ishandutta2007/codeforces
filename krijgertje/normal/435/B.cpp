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

ll a; int maxswap;
int dig[20],len;

void run() {
	cin>>a>>maxswap;

	len=0; for(ll y=a;y>0;y/=10) dig[len++]=y%10;

	int left=maxswap;
	for(int i=len-1;i>=0;--i) {
		int best=i;
		for(int j=i-1;j>=0;--j) if(i-j<=left&&dig[j]>dig[best]) best=j;
		FOR(j,best,i) swap(dig[j],dig[j+1]),--left;
	}
	for(int i=len-1;i>=0;--i) printf("%d",dig[i]); puts("");

}

int main() {
	run();
	return 0;
}