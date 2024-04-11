#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],u,v,x,ans,n1,n2;
vector<int> b[maxn];
struct pa{
int l;
int r;
}f;

pa dfs(int nod,int p){
    int sum1=0,sum2=0;
        sum1+=(a[nod]==1),sum2+=(a[nod]==2);
    for(auto i:b[nod]){
    if(i!=p){
        f=dfs(i,nod);
        sum1+=f.l,sum2+=f.r;
    }
    }
    if((sum1==n1&&sum2==0)||(sum2==n2&&sum1==0)){
                    ans++;
            }
    return {sum1,sum2};
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1){
            n1++;
        }
        else if(a[i]==2){
            n2++;
        }
    }
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        b[v].push_back(u);
        b[u].push_back(v);
   }
    dfs(1,0);
    printf("%d\n",ans);
}