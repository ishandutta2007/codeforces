#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int P = 998244353;

int a[N], n, b[N], c[N];
pair <int, int> p[N];

int fa[N], si[N];

void init(int n) {
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        si[i] = 1;
    }
}

int f(int x) {
    if (x == fa[x]) return x;
    else return fa[x] = f(fa[x]);
}

void un(int x, int y) {
    x = f(x), y = f(y);
    if (si[x] > si[y]) swap(x, y);
    si[y] += si[x];
    fa[x] = y;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        init(n);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = 0;
        }
        int cnt = n, k = 0;
        while (cnt) {
            int x = 0, y;
            for(int i = 1; i <= n; i++) {
                if (!b[i]) {
                    if (x < a[i]) {
                        x = a[i];
                        y = i;
                    }
                }
            }
            b[y] = 1;
            cnt--;
            int z;
            for(int i = 0; i < x; i++) {
                cout << "? " << y << endl << flush;
                cin >> z;
                un(y, z);
                if (b[z]) break;
                else {
                    b[z] = 1;
                    cnt--;
                }
            }
        }
        cout << "!";
        for(int i = 1; i <= n; i++) {
            cout << " " << f(i);
        }
        cout << endl << flush;
    }
    return 0;
}