#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 200100;
const int maxq = 50005;
const int block = 700;

int n, q;
int ql[maxq], qr[maxq];
int p[maxn];

int bit1[maxn];
void upd1(int i, int v) { for (i++; i < maxn; i += i & -i) bit1[i] += v; }
int qry1(int i) { int ret = 0; for (i++; i > 0; i -= i & -i) ret += bit1[i]; return ret; }

/*
int bit2[2 * block + 5];
void upd2(int i, int v) { for (i++; i < 2 * block + 5; i += i & -i) bit2[i] += v; }
int qry2(int i) { int ret = 0; for (i++; i > 0; i -= i & -i) ret += bit2[i]; return ret; }
*/

bool in[maxn];
int ind[2 * block + 5], sze;
int val[2 * block + 5];
int p2[2 * block + 5];

int ansl[2 * block + 5][2 * block + 5];

int getval(int l, int r, int li, int ri, int lv, int rv) {
    int ret = 0;
    ret += l + p[l] - 2 * ansl[li][lv];
    ret += r + p[r] - 2 * ansl[ri][rv];
    for (int i = 0; i < sze; i++) {
        if (i < li) {
            if (p2[i] > p2[li]) ret++;
        } else if (li < i) {
            if (p2[i] < p2[li]) ret++;
        }

        if (i < ri) {
            if (p2[i] > p2[ri]) ret++;
        } else if (ri < i) {
            if (p2[i] < p2[ri]) ret++;
        }
    }

    if (p2[li] > p2[ri]) ret--;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) p[i] = i + 1;
    for (int i = 0; i < q; i++) {
        cin >> ql[i] >> qr[i];
        ql[i]--, qr[i]--;
        if (ql[i] > qr[i]) swap(ql[i], qr[i]);
    }

    for (int t = 0; t < q; t += block) {
        int nd = min(q, t + block);
        memset(in, 0, sizeof(in));
        sze = 0;

        for (int i = t; i < nd; i++) {
            ind[sze++] = ql[i];
            ind[sze++] = qr[i];
        }
        sort(ind, ind + sze); sze = unique(ind, ind + sze) - ind;
        for (int i = 0; i < sze; i++) {
            val[i] = p[ind[i]];
            p2[i] = val[i];
            in[ind[i]] = 1;
        }
        sort(val, val + sze);

        ll ans = 0;
        int cnt = 0;
        memset(bit1, 0, sizeof(bit1));
        for (int i = 0; i < n; i++) {
            ans += i - qry1(p[i]);
            upd1(p[i], 1);
        }

        memset(bit1, 0, sizeof(bit1));
        for (int i = 0; i < n; i++) {
            if (in[i]) {
                for (int j = 0; j < sze; j++)
                    ansl[cnt][j] = qry1(val[j]);
                cnt++;
            } else upd1(p[i], 1);
        }

        for (int i = t; i < nd; i++) {
            int l = ql[i], r = qr[i];
            int li = lower_bound(ind, ind + sze, l) - ind;
            int ri = lower_bound(ind, ind + sze, r) - ind;
            int lv = lower_bound(val, val + sze, p[l]) - val;
            int rv = lower_bound(val, val + sze, p[r]) - val;
            ans -= getval(l, r, li, ri, lv, rv);
            swap(p[l], p[r]);
            swap(p2[li], p2[ri]);
            ans += getval(l, r, li, ri, rv, lv);
            cout << ans << '\n';
        }
    }
}