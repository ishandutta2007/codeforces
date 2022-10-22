#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MX = (1<<19);
const int INF = 1e18;

int n, q;
int a[MX][3], l[MX], r[MX], k[MX];
int sm[MX][3];
vector<int> endsat[MX];
int s[MX], f[MX];

struct SegMax {
    int seg[MX*2];
    void set(int i, int v, int p=1, int l=0, int r=MX-1) {
        if (i < l || i > r) return;
        if (l == r) {
            seg[p] = v;
            return;
        }
        int m=(l+r)/2;
        set(i,v,p*2,l,m);
        set(i,v,p*2+1,m+1,r);
        seg[p] = max(seg[p*2], seg[p*2+1]);
    }
    int get(int i, int j, int p=1, int l=0, int r=MX-1) {
        if (j < l || i > r) return -INF;
        if (i <= l && j >= r) return seg[p];
        int m = (l+r)/2;
        return max(get(i,j,p*2,l,m), get(i,j,p*2+1,m+1,r));
    }
} segmax, segs;

struct Seg {
    int sega[MX*2], segb[MX*2], segc[MX*2];
    void build() {
        for (int p=MX; p!=0; p--) {
            sega[p] = max(sega[p*2], sega[p*2+1]);
            segb[p] = max(segb[p*2], segb[p*2+1]);
            segc[p] = max(max(segc[p*2], segc[p*2+1]), sega[p*2] + segb[p*2+1]);
        }
    }
    tuple<int,int,int> get(int i, int j, int p, int l, int r) {
        if (i <= l && j >= r) return {sega[p], segb[p], segc[p]};
        int a1, b1, c1, a2, b2, c2;
        int m=(l+r)/2;
        if (j <= m) return get(i,j,p*2,l,m);
        if (i > m) return get(i,j,p*2+1,m+1,r);
        tie(a1,b1,c1) = get(i,j,p*2,l,m);
        tie(a2,b2,c2) = get(i,j,p*2+1,m+1,r);
        return {max(a1,a2), max(b1,b2), max(max(c1,c2), a1+b2)};
    }
    int get(int i, int j) {
        int a, b, c;
        tie(a,b,c) = get(i,j,1,0,MX-1);
        return c;
    }
} seg1, seg2;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int j=0; j<3; j++)
        for (int i=0; i<n; i++)
            cin >> a[i][j];
    for (int i=0; i<q; i++)
        cin >> l[i] >> r[i] >> k[i];
    for (int i=0; i<n; i++)
        for (int j=0; j<3; j++)
            sm[i+1][j] = sm[i][j] + a[i][j];
    for (int i=0; i<n; i++) {
        s[i+1] = sm[i+1][0] - sm[i][1];
        f[i+1] = sm[i+1][1] - sm[i][2] + sm[n][2];
        segs.set(i, s[i]);
    }

    for (int i=0; i<q; i++)
        endsat[r[i]].push_back(i);
    
    // fill segmax
    segmax.set(0, -INF);
    for (int i=1; i<=n; i++) {
        int res = -INF;
        for (int j : endsat[i]) {
            res = max(res, segmax.get(l[j]-1, r[j]-1) - k[j]);
            res = max(res, segs.get(l[j], r[j]) - k[j]);
        }
        segmax.set(i, res);
    }

    // find ans
    int ans = -INF;
    for (int i=1; i<=n; i++) {
        seg1.sega[i+MX] = s[i];
        seg1.segb[i+MX] = f[i];
        seg1.segc[i+MX] = s[i] + f[i];
    }
    seg1.build();
    for (int i=1; i<=n; i++) {
        seg2.sega[i+MX] = segmax.get(i-1, i-1);
        seg2.segb[i+MX] = f[i];
        seg2.segc[i+MX] = seg2.sega[i+MX] + f[i];
    }
    seg2.build();
    for (int i=0; i<q; i++) {
        ans = max(ans, seg1.get(l[i],r[i]) - k[i]);
        ans = max(ans, seg2.get(l[i],r[i]) - k[i]);
    }

    cout << ans << endl;
}