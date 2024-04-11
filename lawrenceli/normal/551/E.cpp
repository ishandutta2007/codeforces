#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500100;
const int BLOCK = 700;
const int INF = 1e9 + 5;

typedef long long ll;
typedef pair<int, int> pii;

int n, q;
int a[MAXN], add[MAXN];
vector<pii> ar[MAXN];

void addv(int p, int v) {
    a[p] = min(a[p]+v, INF);
}

void upd(int k) {
    int st = k*BLOCK;
    int nd = min(n, (k+1)*BLOCK);
    for (int i=st; i<n && i<nd; i++)
        ar[k][i-st] = pii(a[i], i);
    sort(ar[k].begin(), ar[k].end());
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) {
        ar[i/BLOCK].push_back(pii(a[i], i));
    }
    for (int i=0; i<n; i++)
        if (i%BLOCK == 0)
            sort(ar[i/BLOCK].begin(), ar[i/BLOCK].end());

    for (int i=0; i<q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            for (; l<r && (l%BLOCK); l++) addv(l, x);
            for (; r>l && (r%BLOCK); r--) addv(r-1, x);
            for (int j=l/BLOCK; j<r/BLOCK; j++) add[j] = min(add[j]+x, INF);
            if (l/BLOCK) upd(l/BLOCK-1);
            upd(r/BLOCK);
        } else {
            int y; cin >> y;
            int lo = 1e9, hi = -1;
            for (int j=0; j<n; j+=BLOCK) {
                int k = j/BLOCK;
                int ind = lower_bound(ar[k].begin(), ar[k].end(), pii(y-add[k], 0))-ar[k].begin();
                if (ind == ar[k].size() || ar[k][ind].first != y-add[k]) continue;
                lo = min(lo, ar[k][ind].second);

                ind = lower_bound(ar[k].begin(), ar[k].end(), pii(y-add[k]+1, 0))-ar[k].begin();
                ind--;
                assert(ar[k][ind].first == y-add[k]);
                hi = max(hi, ar[k][ind].second);
            }
            if (hi == -1) cout << "-1\n";
            else cout << hi-lo << '\n';
        }
    }
}