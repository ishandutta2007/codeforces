//In the name of Allah
#include <bits/stdc++.h>
using namespace std; 

const int maxN = 1000*100 + 10;
int par[maxN];
long long sum[maxN];

int dfind(int u) { 
    return par[u] == -1 ? u : par[u] = dfind(par[u]); 
}
void merge(int u, int v) { 
    u = dfind(u), v = dfind(v); 
    if( u == v ) return; 
    sum[v] += sum[u];
    par[u] = v; 
}

int main() { 
    memset(par, -1, sizeof par);
    int n;
    cin >> n; 
    long long ans = 0;
    for(int i = 2; i < n; i++) 
        for(int j = i + i ; j <= n; j+=i) {
            merge(i, j);
            sum[dfind(i)] += j/i; 
            ans = max(ans, sum[dfind(i)]);
        }
    cout << 4 * ans << endl;
}