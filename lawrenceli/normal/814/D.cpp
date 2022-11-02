#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int maxn = 1005;
const ld eps = 1e-10;
const ld PI = acos(-1.0);

int n;
int x[maxn], y[maxn], r[maxn], p[maxn];

bool in(int i, int j) {
    if (r[i] >= r[j]) return 0;
    ld d = sqrt(ld(x[i] - x[j]) * (x[i] - x[j]) + ld(y[i] - y[j]) * (y[i] - y[j]));
    return d + r[i] - eps < r[j];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (i != j && in(i, j) && (p[i] == -1 || r[p[i]] > r[j]))
                p[i] = j;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (p[i] == -1) q.push(i);

    //for (int i = 0; i < n; i++) cout << p[i] << endl;

    ld ans = 0;
    for (int t = 0; !q.empty(); t++) {
        int sze = q.size();
        for (int i = 0; i < sze; i++) {
            int a = q.front(); q.pop();
            ld area = ld(r[a]) * r[a];
            //cout << i << ' ' << area << endl;
            if (t == 0) ans += area;
            else if (t & 1) ans += area;
            else ans -= area;

            for (int b = 0; b < n; b++)
                if (p[b] == a)
                    q.push(b);
        }
    }

    cout << fixed << setprecision(10) << ans * PI << '\n';
}