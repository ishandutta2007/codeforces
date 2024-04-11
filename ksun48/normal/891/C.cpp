#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 600000
vector<vector<int> > qlist[MAXN];
vector<int> whichq[MAXN];


vector<int> edges[MAXN];

struct UF{
    int n;
    vector<int> par;
    UF(int n) : n(n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    void join(int a, int b){
        par[find(a)] = find(b);
    }
};
int u[MAXN], v[MAXN], w[MAXN];

int main(){

    int n, m;
    scanf("%d%d", &n, &m);

    UF uf(n);

    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &u[i], &v[i], &w[i]);
        u[i]--; v[i]--;
        edges[w[i]].push_back(i);
    }
    int q;
    scanf("%d", &q);

    vector<int> ans(q, 1);

    for(int tt = 0; tt < q; tt++){
        int k;
        scanf("%d", &k);
        vector<pair<int,int> > ids;
        for(int j = 0; j < k; j++){
            int a;
            scanf("%d", &a);
            a--;
            ids.push_back(make_pair(w[a], a));
        }
        sort(ids.begin(), ids.end());
        vector<int> cur;
        for(int i = 0; i < ids.size(); i++){
            cur.push_back(ids[i].second);
            if(i + 1 == ids.size() || ids[i].first != ids[i+1].first){
                qlist[ids[i].first].push_back(cur);
                whichq[ids[i].first].push_back(tt);
                cur.clear();
            }
        }
    }
    UF derpy(n);
    for(int a = 0; a < MAXN; a++){
        for(int i = 0; i < qlist[a].size(); i++){
            int qnum = whichq[a][i];
            for(int j = 0; j < qlist[a][i].size(); j++){
                int b = qlist[a][i][j];
                int e1 = uf.find(u[b]);
                int e2 = uf.find(v[b]);
                if(derpy.find(e1) == derpy.find(e2)){
                    ans[qnum] = 0;
                }
                derpy.join(e1, e2);
            }
            for(int j = 0; j < qlist[a][i].size(); j++){
                int b = qlist[a][i][j];
                int e1 = uf.find(u[b]);
                int e2 = uf.find(v[b]);
                derpy.par[e1] = e1;
                derpy.par[e2] = e2;
            }
        }

        for(int i = 0; i < edges[a].size(); i++){
            int b = edges[a][i];
            uf.join(u[b], v[b]);
        }
    }

    for(int i = 0; i < q; i++){
        if(ans[i]){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}