#include <bits/stdc++.h>
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

int cnt;
int dp[1<<24];

int graph[25];

vector<int> c;

void gen(int r, int p, int x){
    if(p == 0 && x == 0){
        //cout << r << endl;
        c.push_back(r);
        return;
    }
    int d = -1;
    int num = 100;
    for(int u = 0; u < cnt; u++){
        if(((p | x) & (1<<u)) == 0) continue;
        int cur = __builtin_popcount(p & (~graph[u]) );
        if(num > cur){
            num = cur;
            d = u;
        }
    }
    int st = p & (~graph[d]);
    st = p;
    //cout << p << " " << r << " " << x << " " << d << " " << st << endl;
    int cp = p;
    int cx = x;
    for(int v = 0; v < cnt; v++){
        if((st & (1<<v)) == 0) continue;
        gen(r | (1<<v), cp & graph[v], cx & graph[v]);
        cp &= (~(1<<v));
        cx |= (1<<v);
    }
}
int solve(int k){
    if(dp[k] != -1) return dp[k];
    if(k == 0){
        dp[k] = 0;
        return dp[k];
    }
    dp[k] = 1000;
    gen(0, k, 0);
    vector<int> q = c;
    c.clear();
    for(int j = 0; j < q.size(); j++){
        assert((k & q[j]) == q[j]);
        dp[k] = min(dp[k], 1 + solve(k ^ q[j] ) );
    }

    return dp[k];
}
int main(){
    int n;
    cin >> n;
    string g[n];
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }

    UF uf(n);
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(g[i][j] == 'A') uf.join(i,j);
        }
    }

    int sz[n];
    for(int i = 0; i < n; i++){
        sz[i] = 0;
    }
    for(int i = 0; i < n; i++){
        sz[uf.find(i)]++;
    }

    map<int,int> l;
    cnt = 0;
    map<int,int> invl;
    for(int i = 0; i < n; i++){
        if(sz[i] > 1){
            l[i] = cnt;
            invl[cnt] = i;
            cnt++;
        }
    }
    if(cnt == 0){
        cout << n-1 << endl;
        return 0;
    }

    int deg[cnt];
    for(int i = 0; i < cnt; i++){
        deg[i] = 0;
        graph[i] = 0;
    }
    int bad = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(sz[i] == 1 || sz[j] == 1) continue;
            if(g[i][j] == 'X'){
                if(uf.find(i) == uf.find(j)){
                    bad = 1;
                }
                graph[l[uf.find(i)]] |= (1 << l[uf.find(j)]);
                graph[l[uf.find(j)]] |= (1 << l[uf.find(i)]);
            }
        }
    }
    if(bad){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < cnt; i++){
        graph[i] = graph[i] ^ ((1<<cnt) - 1);
        graph[i] &= ~(1<<i);
        //cout << graph[i] << " ";
    }

    for(int j = 0; j < (1<<cnt); j++){
        dp[j] = -1;
    }

    int x = solve((1<<cnt)-1);
    cout << x + n-1 << endl;
}