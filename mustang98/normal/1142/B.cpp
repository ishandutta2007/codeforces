#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_log = 19, inf = 1000111222;

int p[max_n];
int m[max_n];
int pl, ml, q;
int nxtp[max_n];
int nxt[max_n][max_log];
int lst[max_n];
int fin[max_n];

struct st {
    int tr[max_n * 4];

    void build(int cur, int l, int r) {
        if (l == r) {
            tr[cur] = fin[l];
            return;
        }
        int mid = (l + r) / 2;
        build(cur * 2, l, mid);
        build(cur * 2 + 1, mid + 1, r);
        tr[cur] = min(tr[cur * 2], tr[cur * 2 + 1]);
    }

    int get(int cur, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) {
            return tr[cur];
        }
        if (qr < l || ql > r) {
            return inf;
        }
        int mid = (l + r) / 2;
        return min(get(cur * 2, l, mid, ql, min(mid, qr)),
                   get(cur * 2 + 1, mid + 1, r, max(mid + 1, ql), qr));
    }
} tr;


int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < max_n; ++i) {
        lst[i] = inf;
    }
    cin >> pl >> ml >> q;
    for (int i = 0; i < pl; ++i) {
        scanf("%d", p + i);
    }
    for (int i = 0; i < ml; ++i) {
        scanf("%d", m + i);
    }
    for (int i = 0; i < pl; ++i) {
        nxtp[p[i]] = p[(i + 1) % pl];
    }
    int n = ml;
    for (int i = n - 1; i >= 0; --i) {
        lst[m[i]] = i;
        int np = nxtp[m[i]];
        nxt[i][0] = lst[np];
    }
    for (int j = 1; j < max_log; ++j) {
        for (int i = 0; i < n; ++i) {
            if (nxt[i][j - 1] == inf) {
                nxt[i][j] = inf;
            } else {
                nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            }
        }
    }
    int len = pl - 1;
    vector<int> p2;
    for (int i = 0; i < 30; ++i) {
        if (len & (1 << i)) {
            p2.PB(i);
        }
    }
    reverse(p2.begin(), p2.end());
    for (int i = 0; i < n; ++i) {
        int ind = i;
        for (int pw : p2) {
            ind = nxt[ind][pw];
            if (ind == inf) {
                break;
            }
        }
        fin[i] = ind;
    }
    tr.build(1, 0, n - 1);
    string s = "";
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;
        int res = tr.get(1, 0, n - 1, l, r);
        if (res <= r) {
            s += '1';
        } else {
            s += '0';
        }
    }
    cout << s << endl;
    return 0;
}