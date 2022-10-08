
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 5e5 + 5;

struct pt {
    int x, y, z;
} p[N];

int n;
vector<int> vx, vy, vz;
int tree[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = INT_MAX;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
void upd(int i, int l, int r, int y, int z) {
    if(l == r) {
        tree[i] = min(tree[i], z);
        return;
    }
    int m = (l + r) / 2;
    if(y <= m) {
        upd(2 * i + 1, l, m, y, z);
    }else {
        upd(2 * i + 2, m + 1, r, y, z);
    }
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
int getmin(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return INT_MAX;
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return min(getmin(2 * i + 1, l, m, L, R), getmin(2 * i + 2, m + 1, r, L, R));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x;
        vx.push_back(p[i].x);
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i].y;
        vy.push_back(p[i].y);
    }
    for(int i = 0; i < n; i++) {
        cin >> p[i].z;
        vz.push_back(p[i].z);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    sort(vz.begin(), vz.end());
    for(int i = 0; i < n; i++) {
        p[i].x = vx.end() - lower_bound(vx.begin(), vx.end(), p[i].x);
        p[i].y = vy.end() - lower_bound(vy.begin(), vy.end(), p[i].y);
        p[i].z = vz.end() - lower_bound(vz.begin(), vz.end(), p[i].z);
    }
    sort(p, p + n, [](pt a, pt b) { return tuple(a.x, -a.y, -a.z) < tuple(b.x, -b.y, -b.z); });
    build(0, 1, n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (getmin(0, 1, n, 1, p[i].y - 1) < p[i].z);
        upd(0, 1, n, p[i].y, p[i].z);
    }
    cout << ans << endl;
}