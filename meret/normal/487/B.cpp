
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;
#define FI first
#define SE second
#define X first
#define Y second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef long double LD;
typedef double D;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define FOREACH(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)(a).size())
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))

int n, max_dif, min_per_piece;

int t[100005];

int dp[100005];

multiset<int> inside;

bool good() {
    auto last = inside.end();
    --last;
    return (*last - *inside.begin() <= max_dif);
}

int main() {
    cin >> n >> max_dif >> min_per_piece;
    REP(i, n) {
        cin >> t[i];
    }
    dp[0] = 0;
    int l = 0;
    REP(i, n) {
        inside.insert(t[i]);
        while (l < i && (dp[l] == -1 || !good())) {
            inside.erase(inside.find(t[l]));
            ++l;
        }
        if (dp[l] != -1 && good() && l + min_per_piece <= i + 1) {
            dp[i + 1] = dp[l] + 1;
        } else {
            dp[i + 1] = -1;
        }
    }
    cout << dp[n] << endl;

}