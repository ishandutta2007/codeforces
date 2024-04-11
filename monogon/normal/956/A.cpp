
#include <bits/stdc++.h>

#define ll long long
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())

using namespace std;

const int N = 55;
int n, m;
string s[N];

int dsu[2 * N];

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

set<int> row[2 * N], col[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(dsu, dsu + 2 * N, -1);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> s[i];
        rep(j, 0, m) {
            if(s[i][j] == '#') {
                join(i, N + j);
            }
        }
    }
    rep(i, 0, n) row[trace(i)].insert(i);
    rep(j, 0, m) col[trace(N + j)].insert(j + N);
    rep(id, 0, 2 * N) {
        for(int i : row[id]) for(int j : col[id]) {
            if(s[i][j - N] != '#') {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
}