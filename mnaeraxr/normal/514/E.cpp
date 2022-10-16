#include <bits/stdc++.h>

using namespace std;

//#define endl '\n'

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int> vi;

const int64 oo = 1LL << 58;
const double eps = 1e-9;
const int maxn = 100000 + 1;

const int64 mod = 1000000007;
const int SIZE = 101;

struct matrix{
    int64 M[SIZE][SIZE];

    matrix(){
        memset(M, 0, sizeof M);
    }

    matrix operator *(const matrix &T) const{
        matrix ANS;

        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                for (int k = 0; k < SIZE; ++k){
                    ANS.M[i][j] += M[i][k] * T.M[k][j] % mod;
                    ANS.M[i][j] %= mod;
                }

        return ANS;
    }
};

matrix identity(){
    matrix ANS;

    for (int i = 0; i < SIZE; ++i)
        ANS.M[i][i] = 1;

    return ANS;
}

matrix matexp(matrix M, int p){
    matrix ANS = identity();

    for (int i = 0; p; ++i){
        if (p >> i & 1){
            ANS = ANS * M;
            p ^= 1 << i;
        }

        M = M * M;
    }

    return ANS;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 n, x;
    cin >> n >> x;

    vector<int> freq(102);

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        freq[v]++;
    }

    matrix M;

    for (int i = 0; i < 100; ++i)
        M.M[i][i + 1] = 1;

    freq[0] = -1;

    for (int i = 0; i < 101; ++i)
        M.M[100][i] = (freq[101 - i] - freq[100 - i] + mod) % mod;

    M = matexp(M, x);

    vector<int64> dp(101);
    dp[0] = 1;

    int64 answer = dp[0] * M.M[0][0] % mod;
    int64 ACC = dp[0];

    for (int i = 1; i <= 100; ++i){
        for (int j = 1; j <= i; ++j)
            dp[i] = (dp[i] + dp[i - j] * freq[j] % mod) % mod;

        ACC = (ACC + dp[i]) % mod;
        answer = (answer + ACC * M.M[0][i] % mod) % mod;
    }

    cout << answer << endl;

    return 0;
}