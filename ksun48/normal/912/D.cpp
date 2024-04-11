#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, m, r, k;

LL num(LL a, LL b){
    LL c1 = min(a, n-r+1) - max(1LL, a-r+1) + 1;
    LL c2 = min(b, m-r+1) - max(1LL, b-r+1) + 1;
    return c1*c2;
}
set<pair<LL, pair<LL,LL> > > g;

set<pair<LL,LL> > f;
void add(LL a, LL b){
    g.insert({-num(a, b), {a, b}});
}

int main(){
    cin >> n >> m >> r >> k;

    LL s1 = (n+1)/2;
    LL e1 = (m+1)/2;
    add(s1, e1);
    LL ans = 0;
    while(f.size() < k){
        pair<LL,LL> r = (*g.begin()).second;
        g.erase(g.begin());
        if(f.find(r) != f.end()) continue;
        LL a = r.first;
        LL b = r.second;
        f.insert({a,b});
        ans += num(a,b);
        add(a, b-1);
        add(a, b+1);
        add(a-1, b);
        add(a+1, b);
    }
    double a2 = ans;
    double tot = (n-r+1)*(m-r+1);
    printf("%.10lf\n", a2/tot);
}