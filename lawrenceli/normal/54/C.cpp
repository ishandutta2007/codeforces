#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long long ll;

const int MAXN = 1005;

int N, K;
ll L[MAXN], R[MAXN];
double dp[MAXN][MAXN];

double calc(ll l, ll r) {
    ll ret = 0, cur = 1;
    for (; cur<=r; cur*=10) {
        if (cur == 1e18) {
            ret++; break;
        }
        if (cur*10<=l) continue;
        if (cur<=l && cur*10>l) {
            int a = l/cur;
            if (a==1) {
                if (cur*10<=r) ret += cur*2-l;
                else {
                    int b = r/cur;
                    if (b==1) ret += r-l+1;
                    else ret += cur*2-l;
                }
            }
        } else if (cur*10>r) {
            int b = r/cur;
            if (b==1) ret += r-cur+1;
            else ret += cur;
        } else ret += cur;
    }
    return double(ret)/(r-l+1);
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i=0; i<N; i++) cin >> L[i] >> R[i];
    cin >> K;
    K = ceil(K/100.*N);
    dp[0][0] = 1;
    for (int i=0; i<N; i++) {
        double p = calc(L[i], R[i]);
        for (int j=0; j<N; j++) {
            dp[i+1][j+1] += dp[i][j]*p;
            dp[i+1][j] += dp[i][j]*(1-p);
        }
    }
    double ans = 0;
    for (int k=K; k<=N; k++) ans += dp[N][k];
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}