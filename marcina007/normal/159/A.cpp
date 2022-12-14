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
typedef pair<string, string> P;
typedef vector<int> VI;

#define MAXN 1007
int n, d, t[MAXN];
string A[MAXN],B[MAXN];
set<P> R;

int main(){ 
	//in
	cin >> n >> d;
	REP(i,n) cin >> A[i] >> B[i] >> t[i];
	//sol
	REP(i,n) REP(j,i)
		if(A[i] == B[j] && A[j] == B[i] && t[j] < t[i] && t[i] - t[j] <= d) {
			if(!R.count(P(A[i],B[i]))){
				R.insert(P(A[i],B[i]));
				R.insert(P(B[i],A[i]));
			}
		}
	//out
	cout << R.size()/2 << endl;
	FORE(i,R)
		if(i->X < i->Y)
			cout << i->X << " " << i->Y << endl;
    return 0;
}