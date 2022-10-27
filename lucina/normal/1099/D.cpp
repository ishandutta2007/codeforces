#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,pa[maxn],s[maxn];
vector<int> b[maxn];
bool f[maxn];

void dfs(int nod){
    for(auto i:b[nod]){
            dfs(i);
            if(s[nod]>s[i]&&!f[nod]&&s[i]!=-1){
                printf("-1\n");
                exit(0);
            }
            if(s[nod]==-1){
              s[nod]=s[i];
            }
            if(s[nod]>s[i]&&f[nod]){
                s[nod]=min(s[nod],s[i]);
            }
        }
    return ;
}
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        scanf("%d",&pa[i]);
        b[pa[i]].push_back(i);
        }
    for(int i=1;i<=n;i++){
        scanf("%d",&s[i]);
        if(s[i]==-1)
            f[i]=true;
    }
    dfs(1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]!=-1){
            ans+=(s[i]-s[pa[i]]);
        }
    }
    printf("%lld\n",ans);
}