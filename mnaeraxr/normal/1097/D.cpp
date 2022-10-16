#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int64 mod = 1000000007;

map<int64,int64> fak(int64 n){
    map<int64, int64> F;

    for (int64 i = 2; i * i <= n; ++i){
        while (n % i == 0){
            F[i]++;
            n /= i;
        }
    }

    if (n > 1)
        F[n]++;

    return F;
}

int64 modpow(int64 a, int64 n){
    int64 b = 1;

    while (n){
        if (n & 1)
            b = a * b % mod;
        a = a * a % mod;
        n >>= 1;
    }

    return b;
}

int64 inverse(int64 a){
    return modpow(a, mod - 2);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n;
    int k;

    cin >> n >> k;

    auto F = fak(n);

    vector<int64> inv(70);
    for (int i = 1; i < 70; ++i){
        inv[i] = inverse(i);
    }

    vector<vector<int64>> M(70);

    for (auto f : F){
        int s = f.second + 1;

        if (!M[s].empty()) continue;

        M[s] = vector<int64>(s);
        M[s].back() = 1;

        for (int i = 0; i < k; ++i){
            for (int j = 0; j < s; ++j){
                M[s][j] = M[s][j] * inv[j + 1] % mod;

                for (int t = j + 1; t < s; ++t){
                    M[s][j] += M[s][t] * inv[t + 1] % mod;
                    if (M[s][j] >= mod)
                        M[s][j] -= mod;
                }
            }
        }
    }

    int64 answer = 0;

    vector<pair<int64,int64>> faks;
    for (auto p : F) faks.push_back(p);

    function<void(int, int64, int64)> go = [&](int pnt, int64 prob, int64 num){
        if (pnt == F.size()){
            answer += prob * num % mod;
            if (answer >= mod) answer -= mod;
        }
        else{
            int64 s = faks[pnt].second;
            int64 cur = 1;

            for (int i = 0; i <= s; ++i){
                go(pnt + 1, prob * M[s + 1][i] % mod, num * cur % mod);
                cur *= faks[pnt].first % mod;
            }
        }
    };

    go(0, 1, 1);

    cout << answer << endl;

    return 0;
}