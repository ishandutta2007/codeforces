#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
int n;
const int maxN = 3 * (int)1e5 + 10;
vector < int > green;
vector < int > blue, red, bg, rg;
ll p[maxN];
int tp[maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // G, R, B
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        char s;
        cin >> s;
        if (s == 'G') {
            tp[i] = 0;
            green.push_back(i);
            bg.push_back(i);
            rg.push_back(i);
        }
        else if (s == 'R') {
            tp[i] = 1;
            red.push_back(i);
            rg.push_back(i);
        }
        else {
            tp[i] = 2;
            blue.push_back(i);
            bg.push_back(i);
        }
    }
    if (green.empty()) {
        ll ans = 0;
        if (blue.size() >= 2) {
            ans += p[blue.back()] - p[blue[0]];
        }
        if (red.size() >= 2) {
            ans += p[red.back()] - p[red[0]];
        }
        cout << ans << '\n';
    }
    else {
        ll ans = 0;
        if (bg.size() >= 2) {
            ans += p[bg.back()] - p[bg[0]];
        }
        if (rg.size() >= 2) {
            ans += p[rg.back()] - p[rg[0]];
        }
        for (int i = 0; i + 1 < green.size(); i++) {
            int x = green[i];
            int y = green[i + 1];
            if (x + 1 == y) {
                ans -= (p[y] - p[x]);
                continue;
            }
            int s = lower_bound(blue.begin(), blue.end(), x) - blue.begin();
            //cout << s << " ttu" << endl;
            ll mx;
            if (s == blue.size()) {
                mx = p[y] - p[x];
            }
            else if  (blue[s] > y) {
                mx = p[y] - p[x];
            }
            else {
                mx = p[blue[s]] - p[x];
                for (int j = s; j < blue.size() && blue[j] <= y; j++) {
                    if ((j + 1 == blue.size()) || blue[j + 1] > y) {
                        mx = max(mx, p[y] - p[blue[j]]);
                        break;
                    } else {
                        mx = max(mx, p[blue[j + 1]] - p[blue[j]]);
                    }
                }
            }
            int s2 = lower_bound(red.begin(), red.end(), x) - red.begin();
            ll mx2;
            if (s2 == red.size()) {
                mx2 = p[y] - p[x];
            }
            else if (red[s2] > y) {
                mx2 = p[y] - p[x];
            }
            else {
                mx2 = p[red[s2]] - p[x];
                for (int j = s2; j < red.size() && red[j] <= y; j++) {
                    if ((j + 1 == red.size()) || red[j + 1] > y) {
                        mx2 = max(mx2, p[y] - p[red[j]]);
                        break;
                    } else {
                        mx2 = max(mx2, p[red[j + 1]] - p[red[j]]);
                    }
                }
            }
            if (mx + mx2 > p[y] - p[x]) {
                ans += (p[y] - p[x]);
                ans -= (mx + mx2);
            }
        }
        cout << ans;
    }
    return 0;
}