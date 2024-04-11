#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N;
vi c[4];
vi adj[205];
int deg[205];

int solve(int start) {
    vi _c[4]; ff(i, 1, 3) _c[i] = c[i];
    int _deg[205]; ff(i, 1, N) _deg[i] = deg[i];
    int step = 0, left = N;
    while (left) {
        bool flag = 1;
        while (!_c[start].empty() && flag) {
            flag = 0;
            ff(i, 0, _c[start].size() - 1) if (_deg[_c[start][i]] == 0) {
                flag = 1; --left;
                int u = _c[start][i];
                ff(j, 0, (int)adj[u].size() - 1) --_deg[adj[u][j]];
                _c[start].erase(_c[start].begin() + i);
                break;
            }
        }
        if (left) start = start % 3 + 1, ++step;
    }
    return step + N;
}

int main(void) {
    int x, y;
    cin >> N; ff(i, 1, N) { cin >> x; c[x].pb(i); }
    ff(i, 1, N) {
        cin >> x; deg[i] = x;
        ff(j, 1, x) { cin >> y; adj[y].pb(i); }
    }
    int ans = min(solve(1), min(solve(2), solve(3)));
    cout << ans << endl;
    return 0;
}