#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
#define mp make_pair
#define MOD 1000000007
#define pii pair<ll, ll>
typedef long long ll;
int Abs(int x) {
    return x>0?x:-x;
}

ll n, a[500500], k;
vector<ll> f;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        ans += a[i];
    }
    string s;
    cin >> s;
    ll cnt = 1;
    f.push_back(a[0]);
    for (int i = 0; i+1 < n; i++) {
        if (s[i] == s[i+1]) {
            f.push_back(a[i+1]);
        } else {
            sort(f.begin(), f.end());
            int sz = f.size();
            if (sz >= k) {
                for (int j = 0; j < sz-k; j++) {
                    ans -= f[j];
                }
            }
            f.clear();
            f.push_back(a[i+1]);
        }
    }

    sort(f.begin(), f.end());
    int sz = f.size();
    if (sz >= k) {
        for (int j = 0; j < sz-k; j++) {
            ans -= f[j];
        }
    }
    cout << ans << endl;
    return 0;
}