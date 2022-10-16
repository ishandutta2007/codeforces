#include <cstdio>
#include <iostream>
using namespace std;
const int N = 300005, M = 500005;
int n, m, p[N], sum = 1, ans = 0;
int head[N], numE = 0;
bool st[N];
struct Edge{
    int next, to;
}e[M];
void addEdge(int from, int to){
    e[++numE].next = head[from];
    e[numE].to = to;
    head[from] = numE;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", p + i);
    for(int i = 1; i <= m; i++){
        int u, v; scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    st[p[n]] = true;
    for(int i = n - 1; i; i--){
        int u = p[i], cnt = 0;
        for(int j = head[u]; j; j = e[j].next)
            if(st[e[j].to]) cnt++;
        if(cnt != sum) sum++, st[u] = true;
        else ans++;
    }
    printf("%d\n", ans);
    return 0;
}