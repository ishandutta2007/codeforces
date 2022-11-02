#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 2000

typedef long long ll;
typedef pair<int, int> pii;
typedef double flt;

int n, t;
flt p;

flt dp[MAX + 1][MAX + 1] = {};

// flt pascal[2001][2001] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> p >> t;

    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= t; i++) {
        dp[i][0] = (1.0 - p) * dp[i - 1][0];
        for (int j = 1; j <= i; j++) {
            if (j == n) {
                dp[i][j] = p * dp[i - 1][j - 1] + dp[i - 1][j];
                break;
            } else {
                dp[i][j] = p * dp[i - 1][j - 1] + (1.0 - p) * dp[i - 1][j];
            }
        }
    }

//    for (int i = 0; i <= t; i++) {
//        for (int j = 0; j <= t; j++) {
//            cerr << dp[i][j] << '\t';
//        }
//        cerr << endl;
//    }

    flt ret = 0.0;
    for (int i = 0; i <= n; i++) {
//        cerr << i << ": " << dp[t][i] << endl;
        ret += i * dp[t][i];
    }

    cout.precision(6);
    cout << fixed << ret << endl;

//
//    int maxnt = max(n, t);
//    for (int i = 1; i <= maxnt; i++) {
//        pascal[i][0] = pascal[i][i] = 1;
//        for (int j = 1; j < i; j++) {
//            pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
//        }
//    }
//
//    flt ret = 0.0d;
//
//    flt left = 1.0, right = 1.0;
//    for (int i = 0; i < t; i++) {
//        right *= (1 - p);
//    }
////    cerr << left << ", " << right << endl;
//    // E(x) = Sum ( i * binompdf(t, p, i)
//    for (int i = 1; i <= t; i++) {
//        left *= p;
//        right /= (1 - p);
//
//        ret += min(i, n) * pascal[t][i] * left * right;
//        cerr << i << " " << pascal[t][i] << ' ' << left << ' ' << right << endl;
//    }
//
//    cout.precision(6);
//    cout << fixed << ret << endl;

    return 0;
}