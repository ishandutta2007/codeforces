#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[310000];
int vis[310000];

vector<int> cl, cr;
vector<int> cyc;
int pararray[310000];
int depth[310000];
/*int dfs(int par, int a){
    if(vis[a]) return a;
    vis[a] = 1;
    for(int j = 0; j < edges[a].size(); j++){
        if(edges[a][j] != par){
            int k = dfs(a, edges[a][j]);
            if(k >= 0) cyc.push_back(a);
            if(k == a){
                int l = a;
                int r = a;
                for(int j = 0; j < cyc.size(); j++){
                    l = min(l, cyc[j]);
                    r = max(r, cyc[j]);
                }
                cl.push_back(l);
                cr.push_back(r);
                cyc.clear();
                return -1;
            }
            if(k >= 0){
                return k;
            }
        }
    }
    return -1;
}*/
void dfs(int par, int a, int d){
    if(vis[a] && par != -1 && depth[par] >= depth[a]){
        //cout << par << " " << a << endl;
        int z = par;
        int l = z;
        int r = z;
        while(1){
            z = pararray[z];
            l = min(l, z);
            r = max(r, z);
            if(z == a) break;
        }
        cl.push_back(l);
        cr.push_back(r);
        return;
    }
    if(vis[a]) return;
    vis[a] = 1;
    pararray[a] = par;
    depth[a] = d;
    for(int j = 0; j < edges[a].size(); j++){
        if(edges[a][j] != par) dfs(a, edges[a][j], d+1);
    }
    return;
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        vis[i] = 0;
    }
    for(int i = 0; i < n; i++){
        dfs(-1, i, 0);
    }
    vector<pair<int,int> > g;
    for(int j = 0; j < cl.size(); j++){
        g.push_back(make_pair(cr[j], cl[j]+1));
    }
    g.push_back(make_pair(0,0));
    g.push_back(make_pair(n,n));
    sort(g.begin(), g.end());
    vector<pair<int,int> > h;
    for(int j = 0; j < g.size(); j++){
        if(h.size() >= 1 && h[h.size()-1].second >= g[j].second){
            continue;
        }
        h.push_back(g[j]);
    }
    vector<LL> blocks;
    vector<LL> blocksum;
    LL cursum = 0;
    blocksum.push_back(cursum);
    for(int i = 0; i < h.size()-1; i++){
        for(int j = h[i].first; j < h[i+1].first; j++){
            blocks.push_back(h[i].second);
            cursum += (LL)h[i].second;
            blocksum.push_back(cursum);
        }
    }
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        LL l, r;
        scanf("%lld%lld", &l, &r);
        LL tot = (r-l+2)*(r-l+1)/2;
        l--; r--;
        r++;
        if(blocks[r-1] <= l){
            printf("%lld\n", tot);
        } else {
            LL s = 0;
            LL e = r;
            while(s + 1 < e){
                LL mid = (s+e)/2;
                if(blocks[mid-1] <= l){
                    s = mid;
                } else {
                    e = mid;
                }
            }
            LL ans = blocksum[r] - blocksum[s] - (r-s)*l;
            printf("%lld\n", tot-ans);
        }
    }
}