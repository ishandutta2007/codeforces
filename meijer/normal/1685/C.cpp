#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n; string s;
int a[N];
int sm[N];

int seg[N*2];
int comb(int x, int y) {
    return sm[x] >= sm[y] ? x : y;
}
void buildseg(int i, int j, int p=1, int l=0, int r=N-1) {
    if (i > r || j < l) return;
    if (l == r) {
        seg[p] = l;
        return;
    }
    int m=(l+r)/2;
    buildseg(i,j,p*2,l,m);
    buildseg(i,j,p*2+1,m+1,r);
    seg[p] = comb(seg[p*2], seg[p*2+1]);
}
int getseg(int i, int j, int p=1, int l=0, int r=N-1) {
    if (i > j)
        return i;
    if (i <= l && j >= r) return seg[p];
    int m=(l+r)/2;
    if (j <= m) return getseg(i,j,p*2  ,l,m);
    if (i >  m) return getseg(i,j,p*2+1,m+1,r);
    return comb(getseg(i,j,p*2,l,m), getseg(i,j,p*2+1,m+1,r));
}
int getleft(int i, int j, int v, int p=1, int l=0, int r=N-1) {
    if (sm[seg[p]] < v) return -1;
    if (j < l || i > r) return -1;
    if (l == r) return seg[p];

    int m=(l+r)/2;
    if (i <= l && j >= r) {
        if (sm[seg[p*2]] >= v)
            return getleft(i,j,v,p*2,l,m);
        return getleft(i,j,v,p*2+1,m+1,r);
    }
    int res = getleft(i,j,v,p*2,l,m);
    if (res != -1)
        return res;
    return getleft(i,j,v,p*2+1,m+1,r);
}
int getright(int i, int j, int v, int p=1, int l=0, int r=N-1) {
    if (sm[seg[p]] < v) return -1;
    if (j < l || i > r) return -1;
    if (l == r) return seg[p];

    int m=(l+r)/2;
    if (i <= l && j >= r) {
        if (sm[seg[p*2+1]] >= v)
            return getright(i,j,v,p*2+1,m+1,r);
        return getright(i,j,v,p*2,l,m);
    }
    int res = getright(i,j,v,p*2+1,m+1,r);
    if (res != -1)
        return res;
    return getright(i,j,v,p*2,l,m);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        vector<array<int,2>> ans;

        for (int i=0; i<n*2; i++)
            a[i] = s[i] == '(' ? 1 : -1;

        sm[0] = 0;
        for (int i=0; i<n*2; i++)
            sm[i+1] = sm[i] + a[i];
        buildseg(0,n*2);

        vector<int> neg;
        for (int i=0; i<=n*2; i++)
            if (sm[i] < 0)
                neg.push_back(i);
        // for (int i=0; i<=n*2; i++)
            // cout << sm[i] << ' ';
        // cout << endl;
        
        int x = 0;
        while (x < neg.size()) {
            int y = x;
            while (y+1 < neg.size()
                && sm[getseg(neg[x], neg[y+1])] <= sm[getseg(0, neg[x]-1)] + sm[getseg(neg[y+1]+1,n*2)]) {
                y++;
            }
            int val = sm[getseg(neg[x], neg[y])];
            int lsm = sm[getseg(0,neg[x]-1)];
            if (lsm >= val) lsm = val;
            int rsm = val - lsm;
            ans.push_back({getright(0, neg[x]-1, lsm), getleft(neg[y]+1, n*2, rsm)});
            x = y+1;
        }

        cout << ans.size() << endl;
        for (auto p : ans)
            cout << p[0]+1 << " " << p[1] << endl;
    }
}