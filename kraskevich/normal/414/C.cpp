#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second

const int N = (int)2e6;

long long func[22];
int h, sz;
long long a[N];
long long ans[N];
long long buf[N];
long long mx[N];

void build(int hh, int l, int r) {
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(hh - 1, l, m);
    build(hh - 1, m + 1, r);
    int pl = l;
    int pr = m + 1;
    int tot = 0;
    while (pl != m + 1 || pr != r + 1) {
        if (pl == m + 1) {
            buf[tot++] = a[pr];
            pr++;
            continue;
        }
        if (pr == r + 1) {
            buf[tot++] = a[pl];
            func[hh] += pr - m - 1;
            pl++;
            continue;
        }
        if (a[pl] <= a[pr]) {
            buf[tot++] = a[pl];
            func[hh] += pr - m - 1;
            pl++;
            continue;
        } else {
            buf[tot++] = a[pr];
            pr++;
            continue;
        }
    }
    for (int i = l; i <= r; i++)
        a[i] = buf[i - l];
    long long suf = 0;
    for (int i = r; i >= l; i--) {
        if (i < r && a[i] != a[i + 1])
            suf = r - i;
        mx[hh] += suf;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> h;
    sz = (1 << h);
    for (int i = 0; i < sz; i++)
        cin >> a[i];
    for (int hh = 0; hh <= h; hh++)
        func[hh] = 0;
    for (int hh = 0; hh <= h; hh++)
        mx[hh] = 0;
    build(h, 0, sz - 1);
    //cerr << endl;
    //for (int hh = 0; hh <= h; hh++)
     //   cerr << mx[hh] << endl;
    for (int hh = 1; hh <= h; hh++)
        func[hh] += func[hh - 1];
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int level;
        cin >> level;
        long long delta = mx[level] - 2 * func[level];
        for (int hh = level; hh <= h; hh++)
            func[hh] += delta;
        for (int hh = 0; hh < level; hh++)
            func[hh] = mx[hh] - func[hh];
        ans[i] = func[h];
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";

    return 0;
}