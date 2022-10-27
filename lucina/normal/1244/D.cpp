#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
using ll = long long;
vector<int> a[maxn];
int cost[3][maxn],n;
int pa[maxn], child[maxn];
int col[maxn];
bool vis[3];
ll ans = 1e18;
int config[maxn];
vector<int> lf;
void dfs(int nod,int p){
    pa[nod] = p;
    for(int i:a[nod]){
        if(i != p){
            child[nod] = i;
            dfs(i, nod);
        }
    }
    return;
}
void color(int nod){
    if(nod == 0) return;
    for(int  i = 0 ; i< 3 ; i++){
        if(i != col[pa[nod]] && i != col[pa[pa[nod]]]){
            col[nod] = i;
        }
    }
    color(child[nod]);
}

int main(){
    scanf("%d", &n);
    for(int j = 0 ;j< 3 ;j++)
    for(int i=1 ; i<= n;i++){
        scanf("%d" , &cost[j][i]);
    }
    int u, v;
    for(int i = 1 ;i< n; i++){
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i =1 ;i<= n;i++){
        if((int)a[i].size() == 1){
            lf.push_back(i);
        }
        else if((int)a[i].size() != 2){
            return !printf("-1");
        }
    }
    if((int)lf.size() != 2) return !printf("-1");
    dfs(lf[0], 0);
    /*for(int i = 1 ;i<= n; i++){
        fprintf(stderr, "%d ",child[i]);
    }
    fprintf(stderr, "\n");
    */
    for(int i = 0 ;i < 3 ;i++){
        for(int  j = 0 ;j< 3 ; j++){
            if(i != j){
                col[lf[0]] = i;
                col[child[lf[0]]] = j;
                color(child[child[lf[0]]]);
                ll tot = 0 ;
                for(int  i = 1 ;i<= n;i++){
                    tot += cost[col[i]][i];
                }
                if(tot < ans){
                    ans = tot;
                    for(int i= 1;i <=n;i++)
                        config[i] = col[i];
                }
            }
        }
    }
    printf("%lld\n",ans);
    for(int i =1 ;i<=n;i++)
        printf("%d ",config[i] + 1);
}
/*
void dfs(int nod,int P){
    pa[nod] = P;
    if((int) a[nod].size() >= 3){
        printf("-1");
        exit(0);
    }
    for(int i:a[nod]){
        if(i != P){
            dfs(i, nod);
        }
    }
    return ;
}
void dfs_col(int nod,int pa){

}

void test(){
    for(int i =1 ;i<= n;i++){
        if(!in.count(i)){
            col[i] = -1;
        }
    }
    dfs_col(1 , 0);
    ll tot = 0;
    for(int i = 1 ;i <= n; i++){
        tot += cost[col[i]][i];
    }
    if(tot < ans){
        ans = tot;
        for(int i = 1 ;i <= n; i++){
            config[i] = col[i];
        }
    }
}
void shit(int x){
    if(x == 3){
        return test();
    }
    for(int i = 0 ; i< 3 ; i++){
    if(!vis[i]){
    col[threenode[x]] = i;
    vis[i] = true;
    shit(x + 1);
    vis[i] = false;
    }
    }
}

int main(){
    scanf("%d", &n);
    for(int j = 0 ;j< 3 ;j++)
    for(int i=1 ; i<= n;i++){
        scanf("%d" , &cost[j][i]);
    }
    int u, v;
    for(int i = 1 ;i< n; i++){
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1 , 0);
    cerr << "ok\n";
    {
        threenode.push_back(1);
        threenode.push_back(a[1][0]);
        if((int)threenode.size() > 1){
            threenode.push_back(a[1][1]);
        }
        else{
            threenode.push_back(a[threenode[1]][0]);
        }
        for(int i:threenode){
            in.insert(i);
        }
    }
    shit(0);
    printf("%lld\n",ans);
    for(int i = 1 ;i<= n;i++){
        printf("%d ",config[i]);
    }
}*/

/*
    Virtual Round 592
*/