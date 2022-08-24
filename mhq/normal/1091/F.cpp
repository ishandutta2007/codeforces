#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = (int)1e5 + 100;
ll l[maxN];
char s[maxN];
int main() {
    srand(239);
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> l[i];
        l[i] *= 2;
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    vector < pair < ll, char > > all;
    for (int i = 1; i <= n; i++) {
        if ((!all.empty()) && (all.back().second == s[i])) {
            all.back().first += l[i];
        }
        else {
            all.emplace_back(l[i], s[i]);
        }
    }
    n = all.size();
    for (int i = 0; i < all.size(); i++) {
        l[i + 1] = all[i].first;
        s[i + 1] = all[i].second;
    }
    ll water_fly = 0;
    ll earth_fly = 0;
    bool water_before = false;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        //cout << ans << " " << water_fly << " " << earth_fly << endl;
        if (s[i] == 'L') {
            ans += l[i];
            if (2 * water_fly >= l[i]) {
                ll a = l[i] / 2;
                ans += 2 * a;
                water_fly -= a;
            }
            else {
                ans += 2 * water_fly;
                l[i] -= 2 * water_fly;
                water_fly = 0;
                if (2 * earth_fly >= l[i]) {
                    ll a = l[i] / 2;
                    ans += 4 * a;
                    earth_fly -= a;
                    continue;
                }
                ans += 4 * earth_fly;
                l[i] -= 2 * earth_fly;
                earth_fly = 0;
                if (water_before) {
                    ans += 3 * l[i];
                    continue;
                }
                else {
                    ans += 5 * l[i];
                    continue;
                }
            }
        }
        else if (s[i] == 'W'){
            water_before = true;
            ans += 3 * (l[i] / 2) + (l[i] / 2);
            water_fly += (l[i] / 2);
        }
        else {
            if (2 * water_fly >= l[i]) {
                ll a = l[i] / 2;
                ans += 2 * a;
                water_fly -= a;
                earth_fly += l[i];
                ans += l[i];
                continue;
            }
            else {
                l[i] -= 2 * water_fly;
                ans += 2 * water_fly;
                ans += 2 * water_fly;
                earth_fly += 2 * water_fly;
                water_fly = 0;
                ans += 5 * (l[i] / 2) + (l[i] / 2);
                earth_fly += (l[i] / 2);
            }
        }
    }
    cout << ans / 2;
    return 0;

}