#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif // LOCAL
#define find areyousuretodothis
vector<int> a[maxn];
bool vis[maxn];
int n,k,ct;
void dfs(int nod){
    vis[nod] = true;
    for(int i:a[nod]){
        if(!vis[i]){
            ct ++;
            dfs(i);
        }
    }
    return ;
}


int main(){
    scanf("%d%d",&n,&k);
    int u,v;
    for(int i=1;i<=k;i++){
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    printf("%d\n",k-ct);
}
/*
    Good Luck
        -Lucina
*/