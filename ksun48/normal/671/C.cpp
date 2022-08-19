#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> idx[210000];

LL cnt = 0;
set<pair<LL,LL> > steps;

void elim(LL a, LL b){
    if(a > b) return;
    vector<pair<LL,LL> > g;
    LL prev = a-1;
    while(!steps.empty()){
        pair<LL,LL> f = *steps.lower_bound({a,-1});
        if(f.second > b) break;
        cnt += (f.first - prev) * (b - f.second + 1);
        prev = f.first;
        g.push_back(f);
        steps.erase(f);
    }
    if(!g.empty()){
        steps.insert({a-1,g[0].second});
        steps.insert({g[g.size()-1].first,b+1});
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        for(int d = 1; d*d <= a[i]; d++){
            if(a[i] % d == 0){
                idx[d].push_back(i);
                if(d != a[i]/d){
                    idx[a[i]/d].push_back(i);
                }
            }
        }
    }

    for(int j = -1; j <= n; j++){
        steps.insert({j,j});
    }
    // which are multiples of a
    LL ans = 0;
    for(LL z = 200000; z >= 1; z--){
        if(idx[z].size() < 2) continue;
        // eliminate both > idx[z][1]
        // eliminate both < a[i
        cnt = 0;
        elim(-1 + 1, idx[z][idx[z].size()-2]-1);
        elim(idx[z][1] + 1, n-1);
        elim(idx[z][0] + 1, idx[z][idx[z].size()-1]-1);
        ans += cnt * z;
    }
    printf("%lld\n", ans);

}