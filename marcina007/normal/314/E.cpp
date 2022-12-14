#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<complex>
#include<bitset>
#include<cstring>
#include<sstream>
#include<iomanip>
#include<cassert>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;
typedef unsigned int uint;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin(); i != (x).end(); ++i)
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset((x),0,sizeof(x))
#define X first
#define Y second
template<class C> inline void maxi(C& a4, C b4) {a4 = max(a4, b4);}
template<class C> inline void mini(C& a4, C b4) {a4 = min(a4, b4);}
const int INF = 1E9+7;
#define MAXN 100011

int n;
string s;
uint dp[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    //in
    cin >> n >> s;
    //sol
    dp[0] = 1;
    REP(q,n) {
        int z = min(q+4, n-q+4);
        FORD(i,z,1) dp[i] = dp[i-1];
        dp[0] = 0;
        if(s[q] == '?')
            FOR(i,0,z) dp[i] += dp[i+2];
        REP(i,4) dp[z+i+1] = 0;
    }
    int cnt = 0;
    FORE(i,s) cnt += (*i == '?' ? 1 : -1);
    if(cnt >= 0) REP(_,cnt/2) dp[0] *= 25;
    //out
    cout << dp[0] << endl;
}