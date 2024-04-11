#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100100;
const int MOD = 1e9 + 9;

int n;
pii pnts[MAXN];
map<pii, int> mp;

bool stable(pii p) {
    int cnt = 0;
    for (int dx=-1; dx<=1; dx++) {
        pii p2 = pii(p.fi+dx, p.se-1);
        if (mp.count(p2)) cnt++;
    }
    return cnt >= 2;
}

bool good(pii p) {
    for (int dx=-1; dx<=1; dx++) {
        pii p2 = pii(p.fi+dx, p.se+1);
        if (mp.count(p2) && !stable(p2)) return 0;
    }
    return 1;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> pnts[i].fi >> pnts[i].se;
        mp[pnts[i]] = i;
    }

    set<int> st;
    for (int i=0; i<n; i++)
        if (good(pnts[i]))
            st.insert(i);

    int ans = 0;
    for (int i=0; i<n; i++) {
        assert(!st.empty());
        int j;
        if (i%2 == 0) j = *st.rbegin();
        else j = *st.begin();

        ans = ll(ans) * n % MOD;
        ans = (ans + j) % MOD;

        st.erase(j);
        mp.erase(pnts[j]);
        for (int dx=-2; dx<=2; dx++)
            for (int dy=-1; dy<=0; dy++) {
                pii p = pii(pnts[j].fi+dx, pnts[j].se+dy);
                if (mp.count(p)) {
                    int k = mp[p];
                    if (good(p)) st.insert(k);
                    else if (st.count(k)) st.erase(k);
                }
            }
    }

    cout << ans;
}