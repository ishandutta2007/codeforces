#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <cassert>
#include <complex>

using namespace std;

#define ST first
#define ND second
#define VAR(i, x) __typeof(x) i = (x)
#define FORE(i, x) for (VAR(i, (x).begin()); i != (x).end(); ++i)
#define FOR(i,a,b) for (i = (a); i <= (b); ++i)
#define FORD(i,a,b) for (i = (a); i >= (b); --i)
#define REP(i,x) for(i = 0; i < (x); ++i)
#define MP make_pair
#define PB push_back

typedef pair<int, int> PII;
typedef long long LL;

const int MD = (int) 1e9 + 7;

const int N = (int) 1e6 + 5;

inline void ad(int& a, int b) {
    a += b;
    if (a >= MD) {
        a -= MD;
    }
}

int dp[N];
int sum[2];

int main() {
    int n;
    cin >> n;
    dp[0] = 1;
    sum[0] = sum[1] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = sum[1 - i % 2];
        ad(sum[i % 2], dp[i]);
    }
    cout << ((sum[0] + sum[1]) % MD + MD - 2) % MD << endl;
}