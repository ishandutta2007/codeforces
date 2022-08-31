#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
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

int main(){
    int n;
    cin >> n;
    vector<LL> x;
    vector<LL> y;

    map<LL,LL> c;
    for(int i = 0; i < n; i++){
        LL a, b;
        cin >> a >> b;
        b += 1e10;
        x.push_back(a);
        y.push_back(b);
        c[a] = c[b] = 1;        
    }

    map<LL,LL> num;
    int r = 0;
    for(auto it = c.begin(); it != c.end(); it++){
        num[it->first] = r;
        r++;
    }
    UF uf(r);
    for(int i = 0; i < n; i++){
        x[i] = num[x[i]];
        y[i] = num[y[i]];
        uf.join(x[i], y[i]);
    }
    LL cnt[r];
    LL edgecnt[r];
    for(int i = 0; i < r; i++){
        cnt[i] = edgecnt[i] = 0;
    }
    for(int i = 0; i < r; i++){
        cnt[uf.find(i)]++;
    }
    for(int i = 0; i < n; i++){
        edgecnt[uf.find(x[i])]++;
    }
    LL ans = 1;
    for(int i = 0; i < r; i++){
        if(cnt[i] - 1 == edgecnt[i]){
            LL f = 1;
            for(int j = 0; j < cnt[i]; j++){
                f *= 2;
                f %= MOD;
            }
            f--;
            ans = (ans * f) % MOD;
        } else {
            for(int j = 0; j < cnt[i]; j++){
                ans *= 2;
                ans %= MOD;
            }
        }
    }
    cout << ans << endl;

}