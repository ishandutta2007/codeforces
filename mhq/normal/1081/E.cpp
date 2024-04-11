#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2 * (int)1e5 + 10;
vector < int > divs[maxN];
vector < pair < int, int > > all[maxN];
int n;
ll x[maxN];
const ll INF = (ll)1e18;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(239);
    for (int i = 1; i < maxN; i++) {
        for (int j = i; j < maxN; j += i) {
            divs[j].push_back(i);
        }
    }
    for (int i = 1; i < maxN; i++) {
        for (int a : divs[i]) {
            int b =  i / a;
            if (b <= a) continue;
            if ((a % 2) != (b % 2)) continue;
            all[i].push_back(make_pair((b - a) / 2, (b + a) / 2));
        }
    }
    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        cin >> x[i];
    }
    int lst = 0;
    for (int i = 2; i <= n; i += 2) {
        pair < int, int > best = make_pair(-1, -1);
        for (auto t : all[x[i]]) {
            if (t.first > lst) {
                if ((best.first == -1) || (best.second > t.second)) {
                    best = t;
                }
            }
        }
        if (best == make_pair(-1, -1)) {
            cout << "No";
            return 0;
        }
        x[i - 1] = (1LL * best.first * best.first) - (1LL * lst * lst);
        lst = best.second;
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++) cout << x[i] << " ";
    return 0;
}