#include <bits/stdc++.h>

using namespace std;

const int INF = 1000 * 1000 * 1000 + 10;

struct Bit {
    vector<int> f;

    Bit(int n = 0) {
        f.assign(n, -INF);
    }

    int get(int i) {    
        int res = -INF;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            res = max(res, f[i]);
        return res;
    }

    void put(int i, int v) {
        for (; i < f.size(); i = (i | (i + 1)))
            f[i] = max(f[i], v);
    }
};

const int N = 200 * 1000 + 10;

int a[N];
int b[N];

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    Bit ta(n);
    Bit tb(n);
    long long res = 0;
    for (int l = n - 1; l >= 0; l--) {
        ta.put(l, a[l]);
        tb.put(l, -b[l]);
        int lo = l - 1;
        int hi = n;
        while (hi - lo > 1) {
            int m = (lo + hi) / 2;
            if (ta.get(m) < -tb.get(m))
                lo = m;
            else
                hi = m;
        }
        int L = lo;
        lo = l - 1;
        hi = n;
        while (hi - lo > 1) {
            int m = (lo + hi) / 2;
            if (ta.get(m) <= -tb.get(m))
                lo = m;
            else
                hi = m;
        }
        //cerr << lo << " " << L << endl;
        res = res + lo - L;
    }
    cout << res << endl;
    return 0;
}