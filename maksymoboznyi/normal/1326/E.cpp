#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 3e5 + 5;

int n, pu[N], q[N], a[N], ans[N];
int t[4*N], p[4*N];

void push(int v) {
    t[v + v] += p[v];
    p[v + v] += p[v];
    t[v + v + 1] += p[v];
    p[v + v + 1] += p[v];
    p[v] = 0;
}

void upd(int v, int vl, int vr, int l, int r, int val) {
    if (l > r)
        return;
    if (vl == l && vr == r) {
        t[v] += val;
        p[v] += val;
        return;
    }
    push(v);
    int vm = (vl + vr) / 2;
    upd(v + v, vl, vm, l, min(r, vm), val);
    upd(v + v + 1, vm + 1, vr, max(l, vm + 1), r, val);
    t[v] = min(t[v + v], t[v + v + 1]);
}

int pos[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> pu[i], pos[pu[i]] = i;
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    ans[1] = n;
    for (int i = 2; i <= n; i++) {
        bool can = 1;
        ans[i] = ans[i - 1];
        upd(1, 1, n, 1, q[i - 1], 1);
        while (ans[i] > 1) {
            upd(1, 1, n, 1, pos[ans[i]], -1);
            if (t[1] < 0) {
                upd(1, 1, n, 1, pos[ans[i]], 1);
                break;
            } else
                ans[i]--;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}