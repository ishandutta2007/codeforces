#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct UF{
    int n;
    vector<int> par;
    vector<int> bad;
    UF(int n) : n(n) {
        for(int i = 0; i < n; i++) par.push_back(i);
        for(int i = 0; i < n; i++) bad.push_back(0);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    void join(int a, int b){
        int c = find(a);
        int d = find(b);
        par[c] = d;
        bad[d] = max(bad[d], bad[c]);
    }
};

int main(){
    LL n, m;
    cin >> n >> m;
    vector<pair<LL,pair<LL,LL> > > dow;
    UF uf(n);
    for(int i = 0; i < m; i++){
        LL a, b, w;
        cin >> a >> b >> w;
        a--; b--;
        dow.push_back(make_pair(w,make_pair(a,b)));
    }
    sort(dow.begin(), dow.end());
    reverse(dow.begin(), dow.end());
    LL ans = 0;
    for(int j = 0; j < dow.size(); j++){
        LL a = dow[j].second.first;
        LL b = dow[j].second.second;
        if(uf.bad[uf.find(a)] == 1 && uf.bad[uf.find(b)] == 1){
            continue;
        }
        if(uf.find(a) == uf.find(b)){
            uf.bad[uf.find(a)] = 1;
        } else {
            uf.join(a,b);
        }
        ans += dow[j].first;
    }
    cout << ans << endl;
}