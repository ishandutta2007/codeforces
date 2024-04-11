#include<bits/stdc++.h>
using namespace std;
using ll = int64_t;
int const nax = 3e5 + 10;
int n;
vector <int> a[nax];
int b[nax];
int p[nax];
ll dp[nax];
int deg[nax];
ll w[nax];
vector <int> c[nax];
bool d[nax];
vector <int> topo;
bool vis[nax];
bool ok = true;

void topsort(int nod){
    vis[nod]=true;
    d[nod]=true;
    for(int i:c[nod]){
        if(!vis[i]){
            topsort(i);
        }
        else if(d[i]){
            ok=false;
        }
    }
    d[nod]=false;
    topo.push_back(nod);
}


int main () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", b + i);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", p + i);
        if (p[i] != -1) a[p[i]].push_back(i);
        ++ deg[p[i]];
    }


/*
    vector <int> roots;

    for (int i = 1 ; i <= n ; ++ i) {
        if (deg[i] == 0) roots.push_back(i);
    }
*/

    ll ans = accumulate(b + 1, b + 1 + n, 0LL);

    vector <int> leaf;

    for (int i = 1 ; i <= n ; ++ i) {
        if (deg[i] == 0) leaf.push_back(i);
    }

    for (int i = 1 ; i <= n ; ++ i)
        w[i] = b[i];

    while (!leaf.empty()) {
        vector <int> to_append;

        for (int i : leaf) {

            bool dir = false;

            if (w[i] >= 0 && p[i] != -1) {
                    ans += w[i];
                    c[p[i]].push_back(i);
                    w[p[i]] += w[i];
                    dir = true;
            }
            if (p[i] != -1) {
                -- deg[p[i]];
                if (deg[p[i]] == 0) to_append.push_back(p[i]);
                if (!dir) c[i].push_back(p[i]);
            }
        }
        leaf.swap(to_append);
    }

    printf("%lld\n", ans);

    for (int i = 1 ; i <= n ; ++ i) {
        if (!vis[i]) topsort(i);
    }

    assert(ok);

    for (int i : topo) printf("%d ", i);
    puts("");
}
/*
    Very hard game. :(
*/