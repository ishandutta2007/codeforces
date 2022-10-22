#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
 
const int inf = 1e9;
const ll inf64 = 1e18;
 
int main() {
 
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
 
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    const int X = 2.5e6 + 5;
    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i + 1;
    sort(a.begin(), a.end());
 
    if (n <= 5000) {
        vector<pii> any(X, make_pair(-1, -1));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int value = a[j].first - a[i].first;
                if (any[value] != make_pair(-1, -1)) {
                    auto [p, q] = any[value];
                    int I = a[i].second;
                    int J = a[j].second;
                    int P = a[p].second;
                    int Q = a[q].second;
                    cout << "YES\n";
                    cout << Q << " " << I << " " << J << " " << P << "\n";
                    return 0;
                }
            }
            for (int j = i - 1; j >= 0; j--) {
                int value = a[i].first - a[j].first;
                any[value] = {j, i};
            }
        }
        cout << "NO\n";
        return 0;
    }
 
    mt19937 rnd(42);
 
    vector<int> where(X);
    int timer = 0;
 
    for (int diff = 0;;diff++) {
        pii l = {-1, -1}, r = {-1, -1};
        timer++;
        for (int i = 0; i < n; i++) {
            int x = a[i].first - diff;
            if (x >= 0 && where[x] == timer) {
                l = {-1, i};
                break;
            }
            where[a[i].first] = timer;
        }
        timer++;
        for (int i = n - 1; i >= 0; i--) {
            int x = a[i].first + diff;
            if (x < X && where[x] == timer) {
                r = {i, -1};
                break;
            }
            where[a[i].first] = timer;
        }
        if (l.second == -1 || r.first == -1)
            continue;
        for (int i = 0; i < n; i++) {
            if (a[i].first + diff == a[l.second].first) {
                l.first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (a[i].first - diff == a[r.first].first) {
                r.second = i;
                break;
            }
        }
        int P = a[l.first].second;
        int Q = a[l.second].second;
        int I = a[r.first].second;
        int J = a[r.second].second;
        cout << "YES\n";
        cout << Q << " " << I << " " << J << " " << P << "\n";
        return 0;
    }
 
    return 0;
}