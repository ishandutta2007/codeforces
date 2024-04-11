#include <bits/stdc++.h>

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int maxn = 100100;

int n, qa[maxn], qt[maxn], qx[maxn];
int vt[maxn], st, vx[maxn], sx;

vector<piii> qrys[maxn];

int ans[maxn];

int rem[3000100], cnt;

int bit[maxn];

void upd(int i, int v) {
    for (i++; i < maxn; i += i & -i)
        bit[i] += v, rem[cnt++] = i;
}

int qry(int i) {
    int ret = 0;
    for (i++; i > 0; i -= i & -i)
        ret += bit[i];
    return ret;
}

void cleanup() {
    for (int i = 0; i < cnt; i++)
        bit[rem[i]] = 0;
    cnt = 0;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> qa[i] >> qt[i] >> qx[i];
        vt[st++] = qt[i];
        vx[sx++] = qx[i];
    }

    sort(vt, vt + st);
    st = unique(vt, vt + st) - vt;
    sort(vx, vx + sx);
    sx = unique(vx, vx + sx) - vx;

    for (int i = 0; i < n; i++) {
        qt[i] = lower_bound(vt, vt + st, qt[i]) - vt;
        qx[i] = lower_bound(vx, vx + sx, qx[i]) - vx;

        qrys[qx[i]].push_back(piii(pii(qa[i], qt[i]), i));
    }

    for (int i = 0; i < sx; i++) {
        for (piii p : qrys[i]) {
            int a = p.A.A, t = p.A.B, qi = p.B;
            if (a == 1) upd(t, 1);
            else if (a == 2) upd(t, -1);
            else ans[qi] = qry(t);
        }
        cleanup();
    }

    for (int i = 0; i < n; i++)
        if (qa[i] == 3) {
            cout << ans[i] << '\n';
        }
}