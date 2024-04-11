#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

int main(){
    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n);
    forn(i, n)
        scanf("%d%d", &x[i], &y[i]);
    vector<int> c(n), k(n);
    forn(i, n)
        scanf("%d", &c[i]);
    forn(i, n)
        scanf("%d", &k[i]);
    
    ++n;
    vector<int> p(n, -1);
    vector<int> d(n, int(1e9));
    vector<bool> used(n);
    
    forn(i, n - 1){
        d[i] = c[i];
        p[i] = n - 1;
    }
    used[n - 1] = true;
    
    long long ans = 0;
    vector<int> vv;
    vector<pair<int, int>> ee;
    
    forn(_, n - 1){
        int v = -1;
        forn(i, n) if (!used[i] && (v == -1 || d[v] > d[i]))
            v = i;
        
        if (p[v] == n - 1)
            vv.push_back(v + 1);
        else
            ee.push_back(make_pair(v + 1, p[v] + 1));
        ans += d[v];
        
        used[v] = true;
        forn(i, n) if (!used[i]){
            long long dist = (k[v] + k[i]) * 1ll * (abs(x[v] - x[i]) + abs(y[v] - y[i]));
            if (dist < d[i]){
                d[i] = dist;
                p[i] = v;
            }
        }
    }
    
    printf("%lld\n", ans);
    printf("%d\n", int(vv.size()));
    for (auto it : vv)
        printf("%d ", it);
    puts("");
    printf("%d\n", int(ee.size()));
    for (auto it : ee)
        printf("%d %d\n", it.first, it.second);
}