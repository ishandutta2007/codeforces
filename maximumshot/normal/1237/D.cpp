#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

struct RMQ {
    vector<int> a; // [0, n)
    int n, LOG;
    vector<int> _log;
    vector<vector<pii>> rmq;

    RMQ(const vector<int>& aa) {
        a = aa;
        n = (int) a.size();
        LOG = 0;
        while ((1 << LOG) <= n) LOG++;
        _log.resize(n + 1);
        for (int i = 2; i <= n; i++) {
            _log[i] = _log[i - 1] + 1;
            if ((1 << _log[i]) > i) _log[i]--;
        }
        rmq.resize(LOG, vector<pii>(n));
        for (int i = 0; i < n; i++) {
            rmq[0][i] = {a[i], i};
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                rmq[j][i] = min(rmq[j - 1][i], rmq[j - 1][i + (1 << (j - 1))]);
            }
        }
    }

    pii get_min(int l, int r) const {
        int lg = _log[r - l + 1];
        return min(rmq[lg][l], rmq[lg][r - (1 << lg) + 1]);
    }
};

struct Fen {
    int n; // [0, n)
    vector<int> mx;

    Fen(int nn) {
        n = nn;
        mx.resize(n, -1);
    }

    void upd(int pos, int val) {
        pos = n - 1 - pos;
        for (int cur = pos; cur < n; cur |= (cur + 1)) {
            mx[cur] = max(mx[cur], val);
        }
    }

    int get_max(int pos) {
        pos = n - 1 - pos;
        int res = -1;
        for (int cur = pos; cur >= 0; cur = (cur & (cur + 1)) - 1) {
            res = max(res, mx[cur]);
        }
        return res;
    }
};

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;

    vector<int> a(4 * n), crd;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i + 2 * n] = a[i + 3 * n] = a[i];
        crd.push_back(a[i]);
    }

    sort(crd.begin(), crd.end());

    vector<int> link(4 * n, -1);
    Fen fen((int) crd.size());

    for (int i = 0; i < 4 * n; i++) {
        int p = lower_bound(crd.begin(), crd.end(), a[i]) - crd.begin();
        int p2 = upper_bound(crd.begin(), crd.end(), 2 * a[i]) - crd.begin();
        link[i] = fen.get_max(p2);
        fen.upd(p, i);
    }

    for (int i = 0; i < 4 * n; i++) {
        link[i] = -link[i];
    }

    RMQ rmq(link);

    for (int i = 0; i < n; i++) {
        int bl = i;
        int br = 4 * n;
        int bm;
        while (br - bl > 1) {
            bm = (bl + br) >> 1;
            if (-rmq.get_min(i, bm).first < i) {
                bl = bm;
            } else {
                br = bm;
            }
        }
        int j = bl;
        cout << (j + 1 < 4 * n ? j - i + 1 : -1) << " ";
    }

    cout << "\n";

    return 0;
}