
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n;;
ll s, l, r;
pair<ll, ll> pay[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        ll sumr = 0;
        for(int i = 0; i < n; i++) {
            cin >> l >> r;
            s -= l;
            sumr += r;
            pay[i] = {l, r};
        }
        sort(pay, pay + n);
        l = pay[n / 2].first, r = sumr;
        ll s0 = s;
        while(l < r) {
            ll m = l + (r - l) / 2 + 1;
            int j = 0;
            s = s0;
            for(int i = n - 1; i >= 0 && j <= n / 2; i--) {
                if(pay[i].second >= m) {
                    s -= max(0LL, m - pay[i].first);
                    j++;
                }
            }
            if(j <= n / 2 || s < 0) {
                r = m - 1;
            }else {
                l = m;
            }
        }
        cout << l << endl;
    }
}