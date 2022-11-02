#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9 + 10;
const int N = 500 * 1000 + 10;
const int B = 700;

long long a[N];
int n;

typedef pair<long long, int> pii;

struct Block {
    vector<pii> data;
    int L;
    int R;
    long long add;

    Block(int l, int r) {
        L = l;
        R = r;
        add = 0;
        for (int i = l; i <= r; i++) {
            data.push_back(pii(a[i], i));
        }
        sort(data.begin(), data.end());
    }

    bool inter(int ql, int qr) {
        return min(R, qr) >= max(L, ql);
    }

    bool covered(int ql, int qr) {
        return ql <= L && R <= qr;
    }

    void makeAdd(int ql, int qr, long long delta) {
        if (!inter(ql, qr))
            return;
        if (covered(ql, qr)) {
            add += delta;
            return;
        }
        for (int i = 0; i < data.size(); i++)
            if (data[i].second >= ql && data[i].second <= qr) {
                data[i].first += delta;
            }
        sort(data.begin(), data.end()); 
    }

    int getFirst(long long x) {
        x -= add;
        pii p = pii(x, 0);
        auto it = lower_bound(data.begin(), data.end(), p);
        if (it == data.end() || it->first != x)
            return INF;
        return it->second;
    }        

    int getLast(long long x) {
        x -= add;
        pii p = pii(x + 1, 0);
        auto it = lower_bound(data.begin(), data.end(), p);
        if (it == data.begin())
            return -INF;
        it--;
        if(it->first == x)
            return it->second;
        return -INF;
    }
};
 
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    int q;
    cin >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<Block> blocks;
    for (int l = 0, r = B; l < n; l += B, r += B) 
        blocks.push_back(Block(l, min(r - 1, n - 1)));
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            for (auto& b : blocks)
                b.makeAdd(l, r, x);                
        } else {
            long long y;
            cin >> y;
            int f = INF;
            int s = -INF;
            for (auto& b : blocks) {
                f = min(f, b.getFirst(y));
                s = max(s, b.getLast(y));
            }
            if (f == INF)
                cout << -1 << "\n";
            else
                cout << s - f << "\n";
        }
    }
    return 0;
}