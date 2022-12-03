#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, a[N], m, b[N];
int si[N], fa[N];
int p[N], q[N];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        si[i] = 1;
    }
}

int f(int x) {
    if (fa[x] == x) return x;
    else return fa[x] = f(fa[x]);
}

void un(int x, int y) {
    x = f(x), y = f(y);
    if (si[x] > si[y]) swap(x, y);
    fa[x] = y;
    si[y] += si[x];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int k, l, cnt;
        init(n);
        for(int i = 1; i <= n; i++) b[i] = 0;
        for(int i = 0; i < m; i++) {
            cin >> k >> l;
            p[i] = k;
            q[i] = l;
            if (f(k) == f(l)) {
                a[i] = 0;
                b[k]++;
                b[l]++;
            }
            else {
                un(k, l);
                a[i] = 1;
            }
        }
        int flag = 1;
        for(int i = 1; i <= n; i++) {
            if (b[i] == 1) {
                flag = 0;
                break;
            }
        }
        int x = -1;
        if (flag) {
            init(n);
            for(int i = 1; i < m; i++) {
                if (a[i] == 0) {
                    x = i;
                    swap(p[i], p[0]);
                    swap(q[i], q[0]);
                    break;
                }
            }
            for(int i = 0; i < m; i++) {
                k = p[i];
                l = q[i];
                if (f(k) == f(l)) {
                    a[i] = 0;
                }
                else {
                    un(k, l);
                    a[i] = 1;
                }
            }
        }
        if (x >= 0) swap(a[x], a[0]);
        for(int i = 0; i < m; i++) {
            cout << a[i];
        }
        cout << endl;
    }
    return 0;
}