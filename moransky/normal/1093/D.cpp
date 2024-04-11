#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 300010, M = 300010, MOD = 998244353;
int n, m, numE, head[N], f[N], ans;
struct Edge{
    int next, to;
}e[M << 1];
void addEdge(int from, int to){
    e[++numE].next = head[from];
    e[numE].to = to;
    head[from] = numE;
}
queue<int> q;
int power(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (LL)res * a % MOD;
        a = (LL)a * a % MOD;
        b >>= 1;
    }
    return res;
}
int main(){
    int T; scanf("%d", &T);
    while(T--){
        while(q.size()) q.pop();
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) head[i] = 0, f[i] = -1;
        numE = 0; ans = 1;
        for(int i = 1; i <= m; i++){
            int u, v; scanf("%d%d", &u, &v);
            addEdge(u, v); addEdge(v, u);
        }
        for(int i = 1; i <= n; i++){
            if(~f[i]) continue;
            int cnt0 = 1, cnt1 = 0;
            f[i] = 0; q.push(i);
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int i = head[u]; i; i = e[i].next){
                    int v = e[i].to;
                    if(f[v] == -1){
                        f[v] = f[u] ^ 1;
                        if(!f[v]) cnt0++;
                        else cnt1++;
                        q.push(v);
                    }else if(f[v] != (f[u] ^ 1)){
                        ans = 0; break;
                    }
                }
                if(!ans) break;
            }
            if(!ans) break;
            ans = (ans * ((LL)(power(2, cnt0) + power(2, cnt1)) % MOD)) % MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}