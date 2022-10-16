#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000001;
const int64 mod = 1000000007;

int F[1 << 21][21];
int G[1 << 21];
int64 P2[1 << 21];
int SIG[1 << 21];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    P2[0] = 1;

    for (int i = 1; i <= n; ++i)
        P2[i] = P2[i - 1] * 2 % mod;

    int top = 0;

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        top = max(top, v);
        F[v][0]++;
    }

    if (top != 0){
        int l = __lg(top);
        top = (1 << (l + 1)) - 1;
    }

    for (int i = top; ~i; --i){
        for (int j = 1; j < 21; ++j){
            F[i][j] = F[i][j - 1];
            if ((i >> (j - 1) & 1) == 0)
                F[i][j] = F[i][j] + F[i + (1 << (j - 1))][j - 1];
        }
    }

    int64 answer = 0;

    SIG[0] = 1;

    for (int i = 0; i <= top; ++i){
        if (i) SIG[i] = -1 * SIG[i & (i - 1)];

        answer += SIG[i] * (P2[ F[i][20] ] - 1);
        answer %= mod;

        if (answer < 0) answer += mod;
    }

    cout << answer << endl;

    return 0;
}