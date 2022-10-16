#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef map<int, LL> MIL;
typedef MIL:: iterator MIT;
const int N = 200010;
int n, a[N];
MIL c[N];
vector<int> G[N];
LL cnt[N];
int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}
void dfs(int u, int last){
    c[u][a[u]]++;
    for(int i = 0; i < G[u].size(); i++){
        int v = G[u][i];
        if(v == last) continue;
        dfs(v, u);
        for(MIT it1 = c[u].begin(); it1 != c[u].end(); it1++){
            for(MIT it2 = c[v].begin(); it2 != c[v].end(); it2++){
                cnt[gcd(it1->first, it2->first)] += it1->second * it2->second;
            }
        }
        for(MIT it = c[v].begin(); it != c[v].end(); it++){
            c[u][gcd(a[u], it->first)] += it->second;
        }
        c[v].clear();
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i), cnt[a[i]]++;
    for(int i = 1; i < n; i++){
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= 200000; i++)
        if(cnt[i]) printf("%d %lld\n", i, cnt[i]);
    return 0;
}