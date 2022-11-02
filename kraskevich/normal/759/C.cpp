#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = (int)1e6;

int add[N];
int val[N];
int pushVal[N];

void push(int i) {
    val[i] += add[i];
    if (2 * i + 2 < N) {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

void upd(int i, int tl, int tr, int l, int r, int delta) {
    push(i);
    if (l == tl && r == tr) {
        add[i] = delta;
        return;
    }
    int m = (tl + tr) / 2;
    if (l <= m)
        upd(2 * i + 1, tl, m, l, min(r, m), delta);
    if (r > m) 
        upd(2 * i + 2, m + 1, tr, max(m + 1, l), r, delta);
    push(2 * i + 1);
    push(2 * i + 2);
    val[i] = max(val[2 * i + 1], val[2 * i + 2]);
}

int getFirst(int i, int tl, int tr) {
    push(i);
    if (val[i] <= 0)
        return -1;
    if (tl == tr)
        return tl;
    push(2 * i + 1);
    push(2 * i + 2);
    int m = (tl + tr) / 2;
    if (val[2 * i + 1] > 0)
        return getFirst(2 * i + 1, tl, m);
    return getFirst(2 * i + 2, m + 1, tr);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int pos, t;
        cin >> pos >> t;
        pos = n - pos;
        if (t == 0)
            upd(0, 0, n - 1, pos, n - 1, -1);
        else {
            int x;
            cin >> x;
            pushVal[pos] = x;
            upd(0, 0, n - 1, pos, n - 1, 1);
        }   
        int f = getFirst(0, 0, n - 1);
        if (f != -1)
            f = pushVal[f];
        cout << f << "\n";         
    }
}