#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
int n, a[maxn], p[maxn], ans[maxn];
bool vis[maxn];
void solve(){
    cin >> n;
    for(int i = 1 ;i <= n;i++){
        a[i] = i;
        scanf("%d", &p[i]);
        vis[i] = false;
    }
    for(int i = 1 ;i <= n; i++){
        if(vis[i]) continue;
        int start = i;
        int cur = p[i];
        vector<int> all ={start};
        // 1 2 3
        // 1 2 3
        while(cur != start){
            all.push_back(p[cur]);
            cur = p[cur];
        }
        for(int i :all){
            ans[i] = (int)all.size() ;
            vis[i] = true;
        }
    }
    for(int i = 1 ;i<= n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}

int main(){
    int q;
    for(cin >> q; q -- ; ){
        solve();
    }
}