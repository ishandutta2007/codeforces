#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;
int t, n, m, a[N], b[N], l[N], r[N];
int pre[N], nxt[N][20], mostl[N], mostr[N];
vector<int> ratl[N], latr[N];

bool possible(int L, int R) {
    copy(a,a+n+1,b);
    for (int i=L; i<=R; i++)
        b[i] = -i;
    set<int> st; int cl = 1;
    for (int i=1; i<=n; i++) {
        while (cl < i && cl < mostl[i])
            st.erase(b[cl++]);
        if (st.count(b[i]))
            return 0;
        st.insert(b[i]);
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=1; i<=n; i++)
            cin >> a[i];
        for (int i=1; i<=m; i++)
            cin >> l[i] >> r[i];
        
        // fill ratl
        for (int i=1; i<=n; i++)
            ratl[i].clear(), latr[i].clear();
        for (int i=1; i<=m; i++)
            ratl[l[i]].push_back(r[i]), latr[r[i]].push_back(l[i]);
        
        // fill mostL
        queue<pair<int,int>> q;
        for (int i=1; i<=n; i++) {
            for (int x : ratl[i])
                q.push({i, x});
            while(!q.empty() && q.front().se < i)
                q.pop();
            mostl[i] = q.empty() ? i : q.front().first;
        }

        // fill mostR
        while(!q.empty())
            q.pop();
        for (int i=n; i>=1; i--) {
            for (int x : latr[i])
                q.push({i, x});
            while(!q.empty() && q.front().se > i)
                q.pop();
            mostr[i] = q.empty() ? i : q.front().first;
        }
        
        // binary search
        int lb=0, ub=n;
        while (lb != ub) {
            int mid=(lb+ub)/2;
            if (possible(1,mid)) ub=mid;
            else lb=mid+1;
        }
        if (lb == 0) {
            cout << 0 << endl;
            continue;
        }

        // fill pre
        map<int,int> mp;
        for (int i=1; i<=n; i++) {
            pre[i] = mp[a[i]] ? mp[a[i]] : i;
            mp[a[i]] = i;
        }

        // fill nxt
        mp.clear();
        for (int i=n; i>=1; i--) {
            nxt[i][0] = mp[a[i]] ? mp[a[i]] : i;
            mp[a[i]] = i;
        }
        for (int j=1; j<20; j++)
            for (int i=0; i<=n; i++)
                nxt[i][j] = nxt[nxt[i][j-1]][j-1];

        // two pointers
        int ans = lb;
        set<int> st; int cr = lb;
        for (int i=1; i<=cr; i++)
            st.insert(a[i]);
        for (int cl=1; cl<=n; cl++) {
            if (pre[cl] != cl && pre[cl] >= mostl[cl])
                break;
            int nxti = cl;
            for (int j=19; j>=0; j--)
                if (nxt[nxti][j] <= cr)
                    nxti = nxt[nxti][j];
            nxti = nxt[nxti][0];
            if (nxti != cl && nxti <= mostr[cl])
                cr = max(cr, nxti);
            ans = min(ans, cr - cl);
        }

        cout << ans << endl;
    }
}