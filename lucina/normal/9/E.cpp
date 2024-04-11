#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
int n,m,pa[maxn],deg[maxn],u,v,x,y;
vector<int> a[maxn];
int findpa(int h){
    return h==pa[h]?h:pa[h]=findpa(pa[h]);
}
void finish(){
    printf("NO");
    exit(0);
}

int main(){
    scanf("%d%d",&n,&m);
    if(m>n)finish();
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        deg[u]++;deg[v]++;
        if(deg[u]>2||deg[v]>2||((findpa(u)==findpa(v))&&i!=n))
            finish();
        else{
            x=findpa(u);y=findpa(v);
            pa[x]=y;
        }
    }
    printf("YES\n%d\n",n-m);
    for(int i=1;i<=n;i++){
        while(deg[i]<2){
            int t=i+(n!=1);
            for(int j=t;j<=n;j++){
                if(deg[j]<2&&(n<=2||m+1==n||findpa(i)!=findpa(j))){
                    x=findpa(i);y=findpa(j);
                    m++;
                    deg[i]++;
                    deg[j]++;
                    printf("%d %d\n",i,j);
                    pa[x]=y;
                    break;
                }
            }
        }
    }
}