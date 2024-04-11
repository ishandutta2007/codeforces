
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2'500'000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pii> a(n);
    rep(i, 0, n) {
        int x;
        cin >> x;
        a[i] = {x, i + 1};
    }
    sort(all(a));
    vector<vector<pii>> sad(N);
    rep(d, 1, n) for(int i = 0; i + d < n; i++) {
        int j = i + d;
        int dif = a[j].first - a[i].first;
        int x = a[i].second, z = a[j].second;
        for(auto &pa : sad[dif]) {
            int w, y;
            tie(w, y) = pa;
            if(x != y && z != y && x != w && z != w) {
                cout << "YES\n";
                cout << x << ' ' << y << ' ' << z << ' ' << w << '\n';
                return 0;
            }
        }
        sad[dif].push_back({x, z});
    }
    cout << "NO\n";
}