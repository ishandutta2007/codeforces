#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, a[N];

struct cell {
    int l, r, mod, kmod;
};

void go(cell &p) {
    cin >> p.mod;
    if (p.mod == -1)
        while (1)
            p.mod = p.mod;
    cin >> p.kmod;
}

void solve(int l, int r, int mod, int kmod) {
    if (kmod == r - l + 1) {
        for (int i = l; i <= r; i++)
            a[i] = mod;
        return;
    }
    vector<cell> q;
    for (int i = l; i <= r; i = i + kmod)
        q.pb({i, min(r, i + kmod - 1), -1, -1});
    for (auto &p: q) {
        cout << "? " << p.l << ' ' << p.r << endl;
        go(p);
    }
    for (int i = 0; i < q.size(); i++) {
        if (q[i].mod == mod) {
            if (q[i].kmod == kmod) {
                for (int j = q[i].l; j <= q[i].r; j++)
                    a[j] = mod;
                q[i].kmod = -1;
                //break;
            } else {
                if (i == 0) {
                    for (int j = q[i].r; j > q[i].r - q[i].kmod; j--)
                        a[j] = mod;
                    for (int j = 1; j <= kmod - q[i].kmod; j++) {
                        a[q[i + 1].l] = mod;
                        q[i + 1].l++;
                    }
                    q[i].r -= q[i].kmod;
                    if (q[i].l > q[i].r)
                        q[i].kmod = -1;
                    else {
                        cout << "? " << q[i].l << ' ' << q[i].r << endl;
                        go(q[i]);
                    }
                    if (q[i + 1].l > q[i + 1].r)
                        q[i + 1].kmod = -1;
                    else {
                        cout << "? " << q[i + 1].l << ' ' << q[i + 1].r << endl;
                        go(q[i + 1]);
                    }
                    //break;
                } else {
                    cout << "? " << q[i - 1].r << ' ' << q[i - 1].r << endl;
                    int x, y;
                    cin >> x;
                    if (x == -1)
                        while (1)
                            x = x;
                    cin >> y;
                    if (x != mod) {
                        for (int j = q[i].r; j > q[i].r - q[i].kmod; j--)
                            a[j] = mod;
                        for (int j = 1; j <= kmod - q[i].kmod; j++) {
                            a[q[i + 1].l] = mod;
                            q[i + 1].l++;
                        }
                        q[i].r -= q[i].kmod;
                        if (q[i].l > q[i].r)
                            q[i].kmod = -1;
                        else {
                            cout << "? " << q[i].l << ' ' << q[i].r << endl;
                            go(q[i]);
                            //cin >> q[i].mod >> q[i].kmod;
                        }
                        if (q[i + 1].l > q[i + 1].r)
                            q[i + 1].kmod = -1;
                        else {
                            cout << "? " << q[i + 1].l << ' ' << q[i + 1].r << endl;
                            go(q[i + 1]);
                            //cin >> q[i + 1].mod >> q[i + 1].kmod;
                        }
                    } else {
                        for (int j = 1; j <= q[i].kmod; j++)
                            a[q[i].l] = mod, q[i].l++;
                        for (int j = q[i - 1].r; j > q[i - 1].r - (kmod - q[i].kmod); j--)
                            a[j] = mod;
                        q[i - 1].r -= (kmod - q[i].kmod);
                        if (q[i].l > q[i].r)
                            q[i].kmod = -1;
                        else {
                            cout << "? " << q[i].l << ' ' << q[i].r << endl;
                            go(q[i]);
                            //cin >> q[i].mod >> q[i].kmod;
                        }
                        if (q[i - 1].l > q[i - 1].r)
                            q[i - 1].kmod = -1;
                        else {
                            cout << "? " << q[i - 1].l << ' ' << q[i - 1].r << endl;
                            go(q[i - 1]);
                            //cin >> q[i - 1].mod >> q[i - 1].kmod;
                        }

                    }
                }
            }
            break;
        }
    }
    for (auto p: q)
        if (p.kmod != -1)
            solve(p.l, p.r, p.mod, p.kmod);
}

int main()
{
    cin >> n;
    cout << "? " << "1 " << n << endl;
    int x, y;
    cin >> x >> y;
    solve(1, n, x, y);
    cout << "! ";
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}