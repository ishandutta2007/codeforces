
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, m, a, b, u, v;
vector<pair<int, int>> vec;
int dsu[N];
bool b1[N], b2[N];

int find(int x) {
    return dsu[x] < 0 ? x : dsu[x] = find(dsu[x]);
}
void join(int x, int y) {
    if((x = find(x)) == (y = find(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> a >> b;
        a--; b--;
        fill(dsu, dsu + n, -1);
        fill(b1, b1 + n, false);
        fill(b2, b2 + n, false);
        vec.clear();    
        for(int i = 0; i < m; i++) {
            cin >> u >> v;
            u--; v--;
            if(u != a && u != b && v != a && v != b) {
                join(u, v);
            }else {
                vec.emplace_back(u, v);
            }
        }
        for(auto p : vec) {
            tie(u, v) = p;
            if(v == a || v == b) swap(u, v);
            (u == a ? b1 : b2)[find(v)] = true;
        }
        ll cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(i == a || i == b || dsu[i] >= 0) continue;
            if(b1[i] && !b2[i]) {
                cnt1 -= dsu[i];
            }else if(!b1[i] && b2[i]) {
                cnt2 -= dsu[i];
            }
        }
        cout << (cnt1 * cnt2) << endl;
    }
}