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
int n,d,b[MAXN],res;

int main(){ 
	//in
	cin >> n >> d;
	REP(i,n) cin >> b[i];
	//sol
	FOR(i,1,n-1) if(b[i] <= b[i-1]){
		int c = (b[i-1] - b[i] + d) / d;
		res += c;
		b[i] += c * d;
	}
	//out
	cout << res << endl;
    return 0;
}