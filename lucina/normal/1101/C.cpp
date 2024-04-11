#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t,n,u,v,l1,r1,l2,r2;
struct pa{
int l;
int r;
int pos;
bool operator<(const pa x)const{
    return l<x.l;
}
}a[maxn];
int fuck[maxn];
int main(){
    scanf("%d",&t);
    int pt=0;
    while(t--){
        scanf("%d",&n);
        l1=0,l2=0,r1=0,r2=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&u,&v);
            a[pt+i]={u,v,i+pt};
        }
        sort(a+pt+1,a+pt+n+1);
       // printf("%d %d\n",a[pt+1].l,a[pt+1].r);
        l1=a[pt+1].l,r1=a[pt+1].r;
        fuck[a[pt+1].pos]=1;
        for(int i=2;i<=n;i++){
            if(a[pt+i].l<=r1){
                fuck[a[pt+i].pos]=1;
                r1=max(r1,a[pt+i].r);
            }
            else{
               // cout<<"BUG\n";
                fuck[a[pt+i].pos]=2;
                l2=(l2==0)?a[pt+i].l:min(l2,a[pt+i].l);
            }
        }
       // printf("%d %d\n",r1,l2);
        if(l2<=r1){
            printf("-1\n");
        }
        else{
            for(int i=1;i<=n;i++){
                printf("%d ",fuck[i+pt]);
            }
            printf("\n");
        }
        pt+=n;
    }


}