#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
set <int> r[nax];
int real_deg[nax];
int deg[nax];
/**
1
10 3
1 2
1 10
2 3
1 5
1 6
2 4
7 10
10 9
8 10

*/

void solve() {

    scanf("%d %d", &n, &k);

    fill(deg + 1, deg + 1 + n, 0);
    fill(real_deg + 1, real_deg + 1 + n, 0);

    for (int i = 1 ; i < n; ++ i) {
        int u, v;
        scanf("%d%d", &u, &v);
        r[u].insert(v);
        r[v].insert(u);
        ++ real_deg[u];
        ++ real_deg[v];
    }

    if (k == 1) {
        printf("%d\n", n - 1);
        return ;
    }

    int ans = 0;
    vector <int> to_sub;
    for (int i = 1 ; i <= n ; ++ i)
        if (real_deg[i] == 1)  {
            int f = *r[i].begin();
            ++ deg[f];
            r[f].erase(r[f].find(i));
            to_sub.push_back(f);
        };


    for (int i : to_sub) -- real_deg[i];

    set <pair <int, int>, greater <pair <int, int> > > setik;


    for (int i = 1 ; i <= n ; ++ i) {
        if (deg[i] > 0)
            setik.emplace(deg[i], i);
    }


    while (!setik.empty() && setik.begin()->first >= k) {
        auto p = *setik.begin();
        setik.erase(setik.begin());
        ans += p.first / k;

        deg[p.second] = p.first % k;
        if (deg[p.second] > 0) {
            setik.emplace(deg[p.second], p.second);
        } else {
            if (!(real_deg[p.second] == 1) || r[p.second].empty()) goto CC;
            assert(real_deg[p.second] == 1 && !r[p.second].empty());
            int parent = *r[p.second].begin();
            if (deg[parent] > 0) {
                setik.erase(setik.find(make_pair(deg[parent], parent)));
                setik.emplace(++ deg[parent], parent);
            } else {
                setik.emplace(++ deg[parent], parent);
            }
      //      printf("fuck %d %d\n", parent, p.second);
            r[parent].erase(r[parent].find(p.second));
            -- real_deg[parent];
        }

        CC:;
    }

    printf("%d\n", ans);
}

int main () {

    int T;
    scanf("%d", &T);

    while (T -- ) {
        solve();
        for (int i = 1 ; i <= n ;++ i)
            r[i].clear();
    }

}