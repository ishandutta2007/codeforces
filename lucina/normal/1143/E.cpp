#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int p[maxn],a[maxn],l[maxn],n,m,q,up[maxn][22],ans[maxn];
vector<int> k;

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        p[a[i]]=a[i-1];
    }
    p[a[1]]=a[n];
     int x,y;
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        up[i][0]=l[p[x]];
        for(int j=1;j<=20;j++){
                up[i][j]=up[up[i][j-1]][j-1];
        }
        l[x]=i;
    }

    for(int i=1;i<=m;i++){
             x=i;
        for(int j=20;j>=0;j--){
            if((1<<j)&(n-1)){
                x=up[x][j];
            }
        }
        ans[i]=max(ans[i-1],x);
    }

    while(q--){
        scanf("%d%d",&x,&y);
        k.push_back(ans[y]>=x?1:0);
    }
    for(int i:k){
        printf("%d",i);
    }
}