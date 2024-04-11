
#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// process all elements in decreasing order
// maintain table of pairs of rows
// when processing an element, consider it with other elements in its column that have already been processed

const int N = 1005;
int n, m, a[N][N], tmp[N];
vi v[N];
bool tab[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<tuple<int, int, int>> ve;
    rep(i, 0, n) rep(j, 0, m) {
        cin >> a[i][j];
        ve.emplace_back(a[i][j], i, j);
    }
    sort(ve.rbegin(), ve.rend());
    for(auto &p : ve) {
        auto [val, i, j] = p;
        for(int i2 : v[j]) {
            if(tab[i][i2]) {
                cout << val << '\n';
                return 0;
            }
            tab[i][i2] = tab[i2][i] = true;
        }
        v[j].push_back(i);
    }
}