#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int MOD = 1e9 + 7;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}


bool is_par(int x) {
    string s = to_string(x);
    int n = s.size();
    for (int i = 0 ; i * 2 < n ; ++ i) {
        if (s[i] != s[n - i - 1]) return false;
    }
    return true;
}
vector <int> p;
int dp[nax];
const int L = 40000;

void precalc() {
    for (int i = 1 ; i <= L ; ++ i) {
        if (is_par(i)) p.push_back(i);
    }
    dp[0] = 1;
    for (int x : p) {
        for (int j = x ; j <= L ; ++ j)
            dp[j] = add(dp[j], dp[j - x]);
    }
}
void solve() {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    precalc();
    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    sigh...
    too many assignments :)
*/