#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 100100;

int n, C, D;
vector<pair<int, int> > vc, vd;
int nc, nd;
pair<int, int> fc[maxn], fd[maxn];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> C >> D;
    for (int i = 0; i < n; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (c == 'C') vc.push_back(MP(b, a));
        else vd.push_back(MP(b, a));
    }

    sort(vc.begin(), vc.end()); reverse(vc.begin(), vc.end());
    sort(vd.begin(), vd.end()); reverse(vd.begin(), vd.end());

    for (pair<int, int> p : vc) {
        while (nc > 0 && fc[nc - 1].B < p.B) nc--;
        fc[nc++] = p;
    }

    for (pair<int, int> p : vd) {
        while (nd > 0 && fd[nd - 1].B < p.B) nd--;
        fd[nd++] = p;
    }

    reverse(fc, fc + nc); reverse(fd, fd + nd);

    while (nc > 0 && fc[nc - 1].A > C) nc--;
    while (nd > 0 && fd[nd - 1].A > D) nd--;

    int best = 0;
    for (int i = 0; i + 1 < vc.size(); i++)
        if (vc[i] == vc[i + 1])
            if (vc[i].A * 2 <= C)
                best = max(best, vc[i].B * 2);

    for (int i = 0; i + 1 < vd.size(); i++)
        if (vd[i] == vd[i + 1])
            if (vd[i].A * 2 <= D)
                best = max(best, vd[i].B * 2);

    if (nc > 0 && nd > 0) best = max(best, fc[nc - 1].B + fd[nd - 1].B);
    if (vc.size() > 1) {
        for (pair<int, int> p : vc) {
            int x = C - p.A;
            int j = lower_bound(fc, fc + nc, MP(x + 1, -1)) - fc - 1;
            if (j >= 0 && fc[j] == p) j--;
            if (j >= 0) best = max(best, p.B + fc[j].B);
        }
    }

    if (vd.size() > 1) {
        for (pair<int, int> p : vd) {
            int x = D - p.A;
            int j = lower_bound(fd, fd + nd, MP(x + 1, -1)) - fd - 1;
            if (j >= 0 && fd[j] == p) j--;
            if (j >= 0) best = max(best, p.B + fd[j].B);
        }
    }

    cout << best << '\n';
}