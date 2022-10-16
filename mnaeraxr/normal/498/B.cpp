#include <bits/stdc++.h>

using namespace std;

#define double long double

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 1LL << 58;
const double eps = 1e-9;
const int maxn = 5010;

double dp[2][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, T;
    cin >> n >> T;

    vector<pair<double,int>> S(n + 2);

    for (int i = 1; i <= n; ++i){
        cin >> S[i].first >> S[i].second;
        S[i].first /= 100;
    }

    S[n + 1] = {0.0, T + 1};

    dp[0][0] = 1.0;

    double answer = 0.0;

    for (int i = 2; i <= n + 1; ++i){
        int L = S[i - 1].second;
        double P = S[i - 1].first;

        if (L == 1){
            for (int t = 1; t <= T; ++t)
                dp[1][t] = dp[0][t - 1];
        }
        else{
            double p1 = 1.0, p2 = 1.0, p3 = 0.0;

            for (int t = 1; t < L; ++t){
                dp[1][t] = (1.0 - P) * dp[1][t - 1] + dp[0][t - 1] * P;
                if (t > 1) p2 *= (1.0 - P);
            }

            p1 = p2 * (1.0 - P); // (1 - P) ^ (L - 1)
            p3 = p2 * P;         // P * (1 - P) ^ (L - 2)

            dp[1][L] = (dp[1][L - 1] - dp[0][0] * p3) * (1.0 - P) + dp[0][0] * p1 + dp[0][L - 1] * P;

            for (int t = L + 1; t <= T; ++t)
                dp[1][t] = (dp[1][t - 1] - dp[0][t - L] * p3 - dp[0][t - L - 1] * p1) * (1.0 - P) + dp[0][t - L] * p1 + dp[0][t - 1] * P;
        }

        double pp = 1.0;

        for (int j = 0; j < S[i].second; ++j){
            answer += 1.0 * (i - 1) * dp[1][T - j] * pp;
            pp *= (1.0 - S[i].first);
        }

        for (int j = 0; j <= T; ++j){
            dp[0][j] = dp[1][j];
            dp[1][j] = 0.0;
        }
    }

    cout.precision(17);
    cout << fixed << answer << endl;

    return 0;
}