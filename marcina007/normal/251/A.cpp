#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <stack>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <complex>
#include <queue>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin(); i != (x).end(); ++i)
#define ALL(x) x.begin(),(x).end()
#define SZ(x) ((x).size())
#define X first
#define Y second
#define CLR(x) memset((x),0,sizeof(x))
typedef long long int LL;
typedef long long unsigned int LLU;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;
#define MAXN 100007

int n,d,a[MAXN];

int main(){
    ios_base::sync_with_stdio ( false );
    //in
    cin >> n >> d;
    REP(i,n) cin >> a[i];
    //sol
    int j = 0;
    LL res = 0;
    REP(i,n) {
        while(j+1 < n && a[j+1] <= a[i]+d) j++;
        LL k = j-i;
        res += ((LL)k-1) * k / 2;
    }
    //out
    cout << res << endl;
    return 0;
}