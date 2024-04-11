#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, k, p[N], rp[N];
int lp[N], vis[N];
int cnt[N], lfe[N], rge[N], a[N], b[N];

int par[N], sz[N];
void builddsu() {
    for (int i=0; i<k; i++)
        par[i]=i, sz[i]=1;
}
int get(int u) {return u==par[u] ? u : par[u] = get(par[u]);}
bool issameset(int x, int y) {return get(x) == get(y);}
void unite(int x, int y) {
    x = get(x), y = get(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x,y);
    par[x] = y;
    sz[y] += sz[x];
}

bool possible(vector<int> q) {
    vector<array<int,2>> segs[2];
    vector<int> loops;
    for (int i=0; i<q.size()-1; i++) {
        int u = q[i], v = p[q[i+1]];
        if (u < v)
            segs[0].push_back({u,v});
        else if (u > v)
            segs[1].push_back({v,u});
        else loops.push_back(u);
    }

    fill(lfe,lfe+n+1,0);
    fill(rge,rge+n+1,0);
    fill(a,a+n+1,0);
    fill(b,b+n+1,0);

    for (int j=0; j<2; j++) {
        fill(cnt,cnt+n+1,0);
        for (auto p : segs[j]) {
            for (int i=p[0]; i<p[1]; i++) {
                a[i] = 1;
                if (cnt[i])
                    return false;
                cnt[i]++;
            }
            for (int i=p[0]+1; i<p[1]; i++) {
                b[i]++;
                if (b[i] == 2)
                    return false;
            }
            lfe[p[0]]++;
            rge[p[1]]++;
        }
        for (auto p : segs[j])
            cnt[p[1]]++;
        for (int x : loops) {
            if (cnt[x])
                return false;
            lfe[x]++;
            rge[x]++;
        }
    }

    builddsu();
    for (int i=1; i<n; i++) {
        if (a[i]) {
            if (issameset(lp[i], lp[i+1]))
                return false;
            unite(lp[i], lp[i+1]);
        }
    }

    builddsu();
    for (int i=1; i<n; i++) {
        if (lfe[i+1] < 2 && rge[i] < 2) {
            // if (q.size() == 3 && q[2] == 4) {
            //     cout << i << ": " << lp[i] << " " << lp[i+1] << endl;
            // }
            unite(lp[i], lp[i+1]);
        }
    }
    if (sz[get(0)] != k)
        return false;

    return true;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=1; i<=n; i++)
            cin >> p[i];
        for (int i=1; i<=n; i++)
            rp[p[i]] = i;
        
        k = 0;
        fill(vis,vis+n+1,0);
        for (int i=1; i<=n; i++) {
            if (vis[i])
                continue;
            int u = i;
            do {
                vis[u] = 1;
                lp[u] = k;
                u = p[u];
            } while (u != i);
            k++;
        }
        
        vector<int> q = {1};
        while (q.size() < n) {
            for (int i=1; i<=n; i++) {
                if (find(all(q), i) == q.end()) {
                    q.push_back(i);
                    if (possible(q))
                        break;
                    q.pop_back();
                }
                if (i == n)
                    q.push_back(i);
            }
        }
        for (int x : q)
            cout << x << " ";
        cout << endl;
    }
}