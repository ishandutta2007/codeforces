#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

#define MAXN 2007
int n,l[MAXN],r[MAXN];
char c[MAXN];
lli res;

int main(){ 
	//in
	scanf("%s",c+1);
	n=strlen(c+1);
	c[0]='!';
	c[n+1]='#';
	//sol
	FOR(i,1,n)
		for(int q=0;c[i-q]==c[i+q];q++) {
			l[i-q]++;
			r[i+q]++;
		}
	FOR(i,1,n)
		for(int q=0;c[i-q]==c[i+q+1];q++) {
			l[i-q]++;
			r[i+q+1]++;
		}
	FOR(i,1,n) r[i] += r[i-1];
	FOR(i,1,n) res += ((lli)r[i]) * l[i+1];
	//out
//	cout << res << endl;
	printf("%I64d\n", res);
    return 0;
}