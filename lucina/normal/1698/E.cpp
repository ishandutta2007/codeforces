#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}

const int nax = 2e5 + 10;
int n, s;
int a[nax];
int b[nax];
int f[nax];
array <int, 2> fuck[nax];
bool used[nax];
/**
    whoopsss...
    Missed that i-th move must choose from range [i, min(i + s, n)]
    ok, it's just count the number of permutation x
    where x - pos(x) <= s
*/


void solve() {
    cin >> n >> s;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        f[a[i]] = i;
    }

    auto ok = [&](int x, int pos) -> bool {
        return pos <= min(n, x + s);
    };
    int ans = 1;

    fill(used + 1, used + 1 + n, false);

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
    }

    for (int i = 1 ; i <= n ; ++ i) {
        fuck[i] = {a[i], b[i]};
    }
    sort(fuck + 1, fuck + 1 + n);
    for (int i = 1 ; i <= n ; ++ i) {
        b[i] = fuck[i][1];
        if (b[i] != -1 && !ok(b[i], i)) {
            ans = 0;
        }
        if (b[i] != -1) used[b[i]] = true;
    }
//    for (int i = 1 ; i <= n ; ++ i) {
//        cout << b[i] << ' ';
//    }
//    cout << '\n';

    int cnt = 0;


    for (int i = n ; i >= max(1, n - s) ; -- i) {
        if (!used[i]) cnt += 1;
    }

    for (int i = n ; i >= 1 ; -- i) {
        if (b[i] == -1) {
            ans = mul(ans, cnt);
            cnt -= 1;
        }
        if (i - s - 1 > 0  && !used[i - s - 1]) {
            cnt += 1;
        }
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