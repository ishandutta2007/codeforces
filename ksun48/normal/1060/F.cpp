#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<vector<int> > edges;

// from this subtree, what's the probability that a cuts happen given k chosen edges (out of n total edges)

LL ncr[55][55];

void init(){
    for(int n = 0; n < 55; n++){
        for(int k = 0; k < 55; k++){
            if(k == 0 || k == n){
                ncr[n][k] = 1;
            } else if(k > n){
                ncr[n][k] = 0;
            } else {
                ncr[n][k] = ncr[n-1][k-1] + ncr[n-1][k];
            }
        }
    }
}

struct dp {
    int E;
    vector<vector<double> > p;
};

dp empty(){
    dp x;
    x.E = 0;
    x.p.resize(1, vector<double>(1, 1.0));
    return x;
}

dp add_edge(dp sub){
    dp x;
    x.E = sub.E + 1;
    x.p.resize(x.E+1, vector<double>(x.E+1, 0) );
    for(int k = 0; k <= x.E; k++){
        for(int a = 0; a <= k; a++){
            if(k < x.E){
                x.p[k][a] += sub.p[k][a] * double(x.E - k) / double(x.E);
            }
            for(int idx = 0; idx < k; idx++){
                x.p[k][a] += sub.p[idx][a-1] / double(x.E);
            }
        }
    }
    return x;
}

dp combine(dp l, dp r){
    dp x;
    x.E = l.E + r.E;
    x.p.resize(x.E+1, vector<double>(x.E+1, 0) );
    for(int i = 0; i <= l.E; i++){
        for(int j = 0; j <= r.E; j++){
            for(int a = 0; a <= i; a++){
                for(int b = 0; b <= j; b++){
                    double prob = double(ncr[l.E][i] * ncr[r.E][j]) / double(ncr[x.E][i+j]);
                    x.p[i+j][a+b] += l.p[i][a] * r.p[j][b] * prob;
                }
            }
        }
    }
    return x;
}

dp dfs(int v, int p){
    dp x = empty();
    for(int a : edges[v]){
        if(a == p) continue;
        x = combine(x, add_edge(dfs(a, v)));
    }
    return x;
}

double solve(int v){
    dp x = dfs(v, -1);
    double ans = 0;
    for(int a = 0; a <= x.E; a++){
        double r = x.p[x.E][a];
        for(int i = 0; i < a; i++){
            r /= 2.0;
        }
        ans += r;
    }
    return ans;
}

int main(){
    init();
    int n;
    cin >> n;
    edges.resize(n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cout << fixed << setprecision(9);
    for(int i = 0; i < n; i++){
        cout << solve(i) << endl;
    }
}