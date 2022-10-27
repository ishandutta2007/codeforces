#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int t,n,m,u,v,c[maxn],c1,c2,f;
bool ch,vis[maxn];
vector<int> a[maxn];
long long ans,p2[maxn],fuck;
void clean(){
    for(int i=1;i<=n;i++){
        while(!a[i].empty())
            a[i].pop_back();
        vis[i]=0,c[i]=0;
    }
    return ;
}
void dfs(int nod){
    vis[nod]=true;
    for(auto &i: a[nod]){
            if(c[nod]==1){
                if(c[i]==0){
                c[i]=2;
                c2++;
                if(!vis[i])
                dfs(i);
                }
                else if(c[i]==1){
                    ch=false;
                    return;
                }
            }
            else if(c[nod]==2){
                if(c[i]==2){
                    ch=false;
                    return ;
                }
                else if(c[i]==0){
                    c[i]=1;
                    c1++;
                    if(!vis[i])
                    dfs(i);
                }
            }
        }
    return ;
    }

int main(){
    scanf("%d",&t);
    p2[0]=1;
    for(int i=1;i<=3e5+2;i++){
        p2[i]=p2[i-1]<<1;
        p2[i]%=mod;
    }
    while(t--){
            clean();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            a[u].push_back(v);
            a[v].push_back(u);
        }
        ans=1;
        for(int j=1;j<=n;j++){
            if(!vis[j]){
                ch=true;
                c1=1,c2=0,c[j]=1;
                dfs(j);
                if(ch){
                    if(c1+c2==1){
                        ans*=3;
                        ans%=mod;
                        }
                    else{
                    fuck=0;
                    fuck=p2[c1]+p2[c2];
                    fuck%=mod;
                    ans*=fuck;
                    ans%=mod;
                    }
                }
                else
                    ans=0;
            }
        }
        printf("%lld\n",ans);
        //clean();
    }

}