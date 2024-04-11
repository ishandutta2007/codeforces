#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 500000
using namespace std;
int t;
int n;
char a[maxn];
char b[maxn];
bool vis[maxn];
int par[maxn];
vector<int> c[30];
int dfs(int u) {
    vis[u]=true;
    int rt=0;
    for(auto v:c[u]) {
        if(!vis[v]) {

            rt+=dfs(v);
            rt++;
        }
    }
    return rt;
}
int main() {
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        scanf("%s",a);
        scanf("%s",b);
        for(int i=0;i<30;i++) vis[i]=false,c[i].clear();
        bool pos=true;
        for(int i=0;i<n;i++) {
            if(b[i]<a[i]) pos=false;
            if(a[i]<b[i]) {
                c[a[i]-'a'].push_back(b[i]-'a');
                c[b[i]-'a'].push_back(a[i]-'a');
            }
        }
        if(!pos) printf("-1\n");
        else {
            int ans=0;
            for(int i=0;i<30;i++) {
                if(!vis[i]) ans+=dfs(i);
            }
            printf("%d\n",ans);
        }
    }
	return 0;
}