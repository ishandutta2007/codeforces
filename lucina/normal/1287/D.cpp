#include<bits/stdc++.h>
using namespace std;
const int N = 2010;
 
int n, root, c[N], sz[N];
vector<int> a[N];
int ans[N];
void dfs_sz(int nod){
    sz[nod] = 1;
    for(int i : a[nod]){
            dfs_sz(i);
            sz[nod] += sz[i];
    }
    if(sz[nod] <= c[nod]){
        printf("NO");
        exit(0);
    }
}
vector<int> f;
 
void dfs(int nod){
    auto it = f.begin() + c[nod]; /// find c[nod] + 1 (th) number
    ans[nod] = *it;
    f.erase(it); // erase it
    for(int i : a[nod]){
        dfs(i);
    }
}
 
int main(){
    scanf("%d", &n);
    for(int i = 1 ;i <= n; i ++){
        int x;
        scanf("%d %d", &x, c + i);
        if(x == 0) root = i;
        else{
            a[x].push_back(i);
        }
    }
    dfs_sz(root);
    for(int i = 1 ;i <= n ;i ++)
        f.push_back(i);
    dfs(root);
    printf("YES\n");
    for(int i = 1; i <= n ;i ++)
        printf("%d ", ans[i]);
}