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

int n;
int a[nax];
int pos[nax];

void solve() {
    cin >> n;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    int x = pos[0];
    int free_spot = 0;
    static bool found[nax];
    fill(found, found + n, false);
    found[0] = true;
    int l = x, r = x;
    int ans = 1;
    for (int i = 1 ; i < n ; ++ i) {
        if (found[i]) {
            ans = mul(ans, free_spot);
            free_spot -= 1;
        } else {
            int where = pos[i];
            while (l > where) {
                l -= 1;
                found[a[l]] = true;
                free_spot += 1;
            }
            while (r < where) {
                r += 1;
                found[a[r]] = true;
                free_spot += 1;
            }
            free_spot -= 1;
        }
    }

    cout << ans << '\n';
}

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        solve();
    }
}