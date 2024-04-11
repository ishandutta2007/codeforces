#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

typedef long long ll;

struct Tree {
    static const int maxn = 100100;
    ll bit[maxn];

    void init() {
        memset(bit, 0, sizeof(bit));
    }

    void upd(int i, int v) {
        //cout << "UPD: " << i << ' ' << v << endl;
        for (i++; i < maxn; i += i & -i) bit[i] += v;
    }

    ll qry(int i) {
        //cout << "QRY: " << i << endl;
        ll ret = 0;
        for (i++; i > 0; i -= i & -i) ret += bit[i];
        return ret;
    }

} tree;

const int maxn = 100100;
const int block = 600;

int n, m, ar[maxn];
int qt[maxn], ql[maxn], qr[maxn];

vector<int> chg;
bool in[maxn];

vector<int> qind;

int last[maxn];

set<int> xpos[maxn];

ll ans[maxn];

bool cmp(int i1, int i2) {
    return qr[i1] < qr[i2];
}

int getk(int k, int l, int r) {
    auto it = xpos[k].lower_bound(r);
    if (it == xpos[k].begin()) return 0;
    auto it2 = xpos[k].lower_bound(l);
    if (it == it2) return 0;
    it--;
    return *it - *it2;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> ar[i];
    for (int i = 0; i < m; i++) {
        cin >> qt[i] >> ql[i] >> qr[i];
        ql[i]--;
    }

    for (int i = 0; i < m; i += block) {
        int nd = min(m, i + block);

        chg.clear();
        qind.clear();
        for (int j = i; j < nd; j++)
            if (qt[j] == 1) {
                chg.push_back(ar[ql[j]]);
                chg.push_back(qr[j]);
            } else qind.push_back(j);

        sort(chg.begin(), chg.end());
        chg.resize(unique(chg.begin(), chg.end()) - chg.begin());

        memset(in, 0, sizeof(in));
        for (int j : chg) in[j] = 1;

        sort(qind.begin(), qind.end(), cmp);

        tree.init();
        memset(last, -1, sizeof(last));
        int p = 0;
        for (int j = 0; j <= n; j++) {
            while (p < qind.size() && qr[qind[p]] <= j) {
                ans[qind[p]] = tree.qry(ql[qind[p]]);
                p++;
            }

            if (j == n) continue;
            int x = ar[j];
            if (in[x]) continue;

            if (last[x] == -1) last[x] = j;
            else {
                int plus = j - last[x];
                tree.upd(0, plus);
                tree.upd(last[x] + 1, -plus);
                last[x] = j;
            }
        }

        for (int j = 0; j < maxn; j++) xpos[j].clear();
        for (int j = 0; j < n; j++) {
            int x = ar[j];
            if (in[x]) xpos[x].insert(j);
        }

        for (int j = i; j < nd; j++) {
            if (qt[j] == 1) {
                int p = ql[j], x = qr[j];
                xpos[ar[p]].erase(p);
                xpos[x].insert(p);
                ar[p] = x;
            } else {
                int plus = 0;
                for (int k : chg)
                    plus += getk(k, ql[j], qr[j]);
                cout << ans[j] + plus << '\n';
            }
        }
    }
}