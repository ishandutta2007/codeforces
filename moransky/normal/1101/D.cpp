#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 200010;
int n, a[N], ans = 1;
vector<int> G[N], p[N], f[N];
bool success = true;
void dfs(int u, int last){
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(v == last) continue;
        dfs(v, u);
        for(int j = 0; j < p[u].size(); j++){
            for(int k = 0; k < p[v].size(); k++){
                if(p[u][j] == p[v][k]){
                    ans = max(ans, f[u][j] + f[v][k]);
                    f[u][j] = max(f[u][j], f[v][k] + 1);
                }
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        if(a[i] != 1) success = false;
        int x = a[i];
        for(int j = 2; j * j <= a[i]; j++){
            if(x % j == 0){
                p[i].push_back(j);
                f[i].push_back(1);
                while(x % j == 0) x /= j;
            }
        }
        if(x > 1) p[i].push_back(x), f[i].push_back(1);
    
    }
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if(success) puts("0");
    else{
        dfs(1, 0);
        printf("%d", ans);
    }
    return 0;
}