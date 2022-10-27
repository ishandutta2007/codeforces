#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
const int MOD = 998244353;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
int n, k;

/**
    Imagine array v_i - i
    The operation took place like
    0 -1 -2 -3 0 -1 -2 -3
    each zeros will be moved to next zero
    -1 -2 -3 0 -1 -2 -3 0
    and add 1 to everything
    0 -1 -2 0 0 -1 -2
    Well, it just shifting array to the left k times
*/

void solve() {
    cin >> n >> k;
    int ans = 1;
    for (int i = 1, x ; i <= n ; ++ i) {
        cin >> x;
        if (x != -1) x = i - 1 - x;
        int from = i + k;
        if (from > n) {
            if (x != -1 && x != i - 1) ans = 0;
            continue;
        }
        if (x == -1) {
            ans = mul(ans, from);
        } else if (x == i - 1) {
            ans = mul(ans, k + 1);
        }
    }

    for (int i = 1 ; i <= k ; ++ i) {
        ans = mul(ans, i);
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}