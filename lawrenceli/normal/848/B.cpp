#include <bits/stdc++.h>

using namespace std;

struct data {
    int g, p, t, i;
};

const int maxn = 100100;

int n, w, h;
data ar[maxn];

int val(data d) { return d.p - d.t; }

bool cmp(data d1, data d2) { return val(d1) < val(d2); }
bool cmp2(data d1, data d2) { return d1.p < d2.p; }

data ver[maxn], hor[maxn];
int vercnt, horcnt;
pair<int, int> par[maxn]; int cnt;
pair<int, int> ans[maxn];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> w >> h;
    for (int i = 0; i < n; i++) {
        cin >> ar[i].g >> ar[i].p >> ar[i].t;
        ar[i].i = i;
    }

    sort(ar, ar + n, cmp);

    for (int i = 0, j; i < n; i = j) {
        vercnt = horcnt = 0;
        for (j = i; j < n && val(ar[j]) == val(ar[i]); j++) {
            if (ar[j].g == 2) ver[vercnt++] = ar[j];
            else hor[horcnt++] = ar[j];
        }

        sort(ver, ver + vercnt, cmp2); reverse(ver, ver + vercnt);
        sort(hor, hor + horcnt, cmp2);

        cnt = 0;
        for (int k = 0; k < horcnt; k++) par[cnt++] = make_pair(hor[k].p, h);
        for (int k = 0; k < vercnt; k++) par[cnt++] = make_pair(w, ver[k].p);

        cnt = 0;
        for (int k = 0; k < vercnt; k++) ans[ver[k].i] = par[cnt++];
        for (int k = 0; k < horcnt; k++) ans[hor[k].i] = par[cnt++];
    }

    for (int i = 0; i < n; i++) cout << ans[i].first << ' ' << ans[i].second << '\n';
}