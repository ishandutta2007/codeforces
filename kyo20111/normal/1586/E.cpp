#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, q, c[300300], l[300300], r[300300], lev[300300], par[300300], chk[300300];
vector<int> v[300300];

void dfs(int u, int p){
    chk[u] = 1, lev[u] = lev[p] + 1, par[u] = p;
    for(auto x : v[u]) if(!chk[x]) dfs(x, u);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b), v[b].push_back(a);
    }

    cin >> q;
    for(int i=1;i<=q;i++){
        cin >> l[i] >> r[i];
        c[l[i]]++, c[r[i]]++;
    }

    int cnt = 0;
    for(int i=1;i<=n;i++) if(c[i] % 2) cnt++;

    if(cnt){
        assert(cnt % 2 == 0);
        cout << "NO\n" << cnt/2 << "\n";
        return 0;
    }

    dfs(1, 0);

    cout << "YES\n";
    for(int i=1;i<=q;i++){

        vector<int> v1, v2;

        int L = l[i], R = r[i];

        while(lev[L] != lev[R]){
            if(lev[L] > lev[R]){
                v1.push_back(L);
                L = par[L];
            }else{
                v2.push_back(R);
                R = par[R];
            }
        }

        while(1){
            v1.push_back(L), v2.push_back(R);
            if(L == R) break;
            L = par[L], R = par[R];
        }

        cout << v1.size() + v2.size() - 1 << "\n";

        v1.pop_back();
        for(int i=0;i<v1.size();i++) cout << v1[i] << " ";
        for(int i=int(v2.size())-1;i>=0;i--) cout << v2[i] << " ";

        cout << "\n";
    }
}