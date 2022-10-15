#include <bits/stdc++.h>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;

const int MAXN = 3e5;
int t1[4*MAXN], t2[4 * MAXN];

int op1(const vector<int>& a, int x, int y) {
    if (x == -1)
        return y;
    if (y == -1)
        return x;
    return a[x] < a[y] ? x : y;
}
int op2(const vector<int>& a, int x, int y) {
    if (x == -1)
        return y;
    if (y == -1)
        return x;
    return a[x] > a[y] ? x : y;
}

void build1(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t1[v] = tl;
    } else {
        int tm = (tl + tr) / 2;
        build1(a, v*2, tl, tm);
        build1(a, v*2+1, tm+1, tr);
        t1[v] = op1(a, t1[v*2], t1[v*2+1]);
    }
}
void build2(const vector<int>& a, int v, int tl, int tr) {
    if (tl == tr) {
        t2[v] = tl;
    } else {
        int tm = (tl + tr) / 2;
        build2(a, v*2, tl, tm);
        build2(a, v*2+1, tm+1, tr);
        t2[v] = op2(a, t2[v*2], t2[v*2+1]);
    }
}

int sum1(const vector<int>& a, int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return -1;
    if (l == tl && r == tr) {
        return t1[v];
    }
    int tm = (tl + tr) / 2;
    return op1(a, sum1(a, v*2, tl, tm, l, min(r, tm)), sum1(a, v*2+1, tm+1, tr, max(l, tm+1), r));
}
int sum2(const vector<int>& a, int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return -1;
    if (l == tl && r == tr) {
        return t2[v];
    }
    int tm = (tl + tr) / 2;
    return op2(a, sum2(a, v*2, tl, tm, l, min(r, tm)), sum2(a, v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build1(a, 1, 0, n-1);
    build2(a, 1, 0, n-1);
    vector<int> dist(n);
    stack<int> st1, st2;
    st1.push(n);
    st2.push(n);
    for (int i = n - 2; i >= 0; i--) {
        dist[i] = 1e9;
        int l = i;
        while (st2.size() > 1 && a[i] > a[st2.top()])
            st2.pop();
        int r = st2.top() - 1;
        if (r > l) {
            dist[i] = min(dist[i], dist[sum1(a, 1, 0, n - 1, l, r)] + 1);
        }
        while (st1.size() > 1 && a[i] < a[st1.top()])
            st1.pop();
        r = st1.top() - 1;
        if (r > l) {
            dist[i] = min(dist[i], dist[sum2(a, 1, 0, n - 1, l, r)] + 1);
        }
        st1.push(i);
        st2.push(i);
    }
    // for (int i = 0; i < n; i++)
    //     cout << dist[i] << " \n"[i + 1 == n];
    cout << dist[0] << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int T;
    cin >> T;
    while (T--) {
        solve();
    }
}