#include <bits/stdc++.h>

using namespace std;

const int maxn = 600005;
int n;
int p[maxn];
int q[maxn];
int ps[maxn];

int tr[4 * maxn];
int lz[4 * maxn];

void push(int node, int l, int r) {
    //cout << "pu " << node << ' ' << l << ' ' << r << ' ' << lz[node] << endl;
    tr[node] += lz[node];
    if (l != r) {
        lz[node*2] += lz[node];
        lz[node*2+1] += lz[node];
    }
    lz[node] = 0;
}

void upd(int node, int l, int r, int pos, int val) {
    //cout << "up " << node << ' ' << l << ' ' << r << ' ' << pos << ' ' << val << endl;
    push(node, l, r);
    if (l > pos) return;
    if (r <= pos) {
        lz[node] += val;
        push(node, l, r);
        return;
    }
    int m = l + r >> 1;
    upd(node * 2, l, m, pos, val);
    upd(node * 2 + 1, m + 1, r, pos, val);
    tr[node] = min(tr[node * 2], tr[node * 2 + 1]);
    //cout << "dd " << node << ' ' << l << ' ' << r << ' ' << tr[node] << endl;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i], ps[p[i]] = i;
    for (int i = 1; i <= n; ++i) cin >> q[i];
    int ans = n;
    cout << ans << ' ';
    for (int i = 1; i < n; ++i) {
        int pos = 2 * q[i];
        //cout << pos << endl;
        upd(1, 1, 2 * n, pos, 1);
        while (true) {
            push(1, 1, 2 * n);
            //cout << i << ' ' << ans << ' ' << tr[1] << endl;
            if (tr[1] < 0) break;
            pos = 2 * ps[ans] - 1;
            upd(1, 1, 2 * n, pos, -1);
            --ans;
        }
        cout << ans + 1 << ' ';
    }
    cout << endl;
    return 0;
}