
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

const int N = 2e5 + 5;
int n, a[N];
pii tree[4 * N];

pii add(const pii &a, const pii &b) {
    return {min(a.first, b.first), max(a.second, b.second)};
}

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = {a[l], a[l]};
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = add(tree[2 * i + 1], tree[2 * i + 2]);
}
pii query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return {INT_MAX, INT_MIN};
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return add(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
bool check(int l, int r) {
    if(l <= 1 || r >= n) return false;
    int mx1 = query(0, 1, n, 1, l - 1).second;
    int mn = query(0, 1, n, l, r).first;
    int mx2 = query(0, 1, n, r + 1, n).second;
    if(mx1 == mn && mx1 == mx2) {
        cout << "YES" << '\n';
        cout << l - 1 << ' ' << r - l + 1 << ' ' << n - r << '\n';
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        cin >> n;
        map<int, vi> ma;
        rep(i, 1, n + 1) {
            cin >> a[i];
            ma[a[i]].push_back(i);
        }
        int minpos = n, maxpos = -1;
        vector<pair<int, vi>> ve(all(ma));
        int mx = *max_element(a + 1, a + n + 1);
        if(sz(ma[mx]) >= 3) {
            cout << "YES" << '\n';
            int pos = ma[mx][1];
            cout << pos - 1 << ' ' << 1 << ' ' << n - pos << '\n';
            goto hell;
        }
        build(0, 1, n);
        reverse(all(ve));
        for(auto &pa : ve) {
            int pos1 = pa.second[0];
            int pos2 = pa.second.back();
            minpos = min(minpos, pos1);
            maxpos = max(maxpos, pos2);
            if(check(minpos, maxpos)) goto hell;
            if(check(minpos - 1, maxpos)) goto hell;
            if(check(minpos, maxpos + 1)) goto hell;
        }
        cout << "NO" << '\n';
        hell:;
    }
}