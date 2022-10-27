#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void plusle(int &a, int b){a+=b;if(a>=MOD)a-=MOD;}
void minun(int &a, int b){a-=b;if(a<0)a+=MOD;}
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if (a<0)a+=MOD;return a;}
int mul(int a, int b){return 1ll*a*b%MOD;}
int power(int a, int64_t b){int res=1;for (;b>0;b >>= 1,a=mul(a,a))if(b&1)res=mul(res,a);return res;}
const int nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];
int d[nax];
int remap[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        remap[a[i]] = i;
        a[i] = i;
    }
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
        b[i] = remap[b[i]];
    }
    for (int i = 1 ; i <= n; ++ i) {
        cin >> d[i];
        d[i] = remap[d[i]];
    }



    static bool vis[nax];
    fill(vis + 1, vis + 1 + n, false);

    int ans = 1;
    for (int i = 1 ; i <= n ; ++ i) {
        if (vis[b[i]]) continue;
        int x = b[i];
        int cyc = 0;
        int sz = 0;
        do {
            sz += 1;
            cyc += d[x] != 0;
            vis[x] = true;
            x = b[x];
        } while (x != b[i]);
        if (sz > 1 && !cyc) {
            ans = mul(ans, 2);
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