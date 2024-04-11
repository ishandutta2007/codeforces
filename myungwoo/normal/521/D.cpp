#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
typedef long long lld;
typedef long double llf;
typedef pair<int,int> pii;

#define MAXN 100005

int K, N, M;
lld A[MAXN];
int type[MAXN];

int main()
{
    scanf("%d%d%d", &K, &N, &M);
    for (int i=1;i<=K;i++) scanf("%lld", A+i);
    
    vector <pii> ass(K+1);
    vector <vector<pii>> add(K+1), mul(K+1);
    for (int i=1;i<=N;i++){
        int sk, v;
        scanf("%d%d%d", type+i, &sk, &v);
        if (type[i] == 1){
            if (ass[sk].fr < v)
                ass[sk] = mp(v, i);
        }
        else if (type[i] == 2){
            add[sk].pb(mp(v, i));
        }else{
            mul[sk].pb(mp(v, i));
        }
    }

    priority_queue <pair<llf, int>> que;
    for (int i=1;i<=K;i++){
        if (ass[i].fr > A[i]) add[i].pb(mp(ass[i].fr-A[i], ass[i].sc));
        sort(add[i].rbegin(), add[i].rend());
        if (sz(add[i]))
            que.push(mp(1 + (long double)add[i][0].fr / A[i], -i));
        for (auto &p: mul[i]) que.push(mp(p.fr, p.sc));
    }

    vector <int> add_idx(K+1);
    vector <int> ans;
    que.push(mp(-1, 0));
    for (int iter=M;iter--;){
        auto q = que.top(); que.pop();
        if (q.fr <= 0) break;
        int x = q.sc;
        if (x > 0){ ans.pb(x); continue; }
        x = -x;
        ans.pb(add[x][add_idx[x]].sc);
        A[x] += add[x][add_idx[x]].fr;
        add_idx[x]++;
        if (add_idx[x] == sz(add[x])) continue;
        que.push(mp(1 + (long double)add[x][add_idx[x]].fr / A[x], -x));
    }
    sort(all(ans), [](const int &a, const int &b){
        return type[a] < type[b];
    });
    printf("%d\n", sz(ans));
    for (int t: ans) printf("%d ", t); puts("");
}