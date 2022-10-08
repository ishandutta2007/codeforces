
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int dsu[N], dmin[N], dmax[N];
int n, m, u, v;

int trace(int x) {
    return dsu[x] < 0 ? x : dsu[x] = trace(dsu[x]);
}
void join(int x, int y) {
    if((x = trace(x)) == (y = trace(y))) return;
    if(dsu[x] > dsu[y]) swap(x, y);
    dmin[x] = min(dmin[x], dmin[y]);
    dmax[x] = max(dmax[x], dmax[y]);
    dsu[x] += dsu[y];
    dsu[y] = x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    fill(dsu, dsu + n, -1);
    for(int i = 0; i < n; i++) {
        dmin[i] = dmax[i] = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--; v--;
        join(u, v);
    }
    int cnt = 0, s = -1;
    for(int i = 0; i < n; i++) {
        int j = trace(i);
        if(s != -1 && s != j) {
            cnt++;
            join(j, s);
        }
        s = trace(j);
        if(dmax[s] == i) s = -1;
    }
    cout << cnt << endl;
}