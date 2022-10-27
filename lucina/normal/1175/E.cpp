/*
This is fucking standard

If Electrification didn't ruin me
If Electrification didn't ruin me
T_____________________T
What IF ELECTRIFICATION DIDN"T TOXIC ME
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,LOG=22;
int n,q,up[maxn][LOG],ma;
struct pa{
    int l,r;
    bool operator<(const pa x)const{
        return l==x.l?r<x.r:l<x.l;
    }
}a[maxn];

int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i].l,&a[i].r);
        ma=max(ma,a[i].r);
    }
    sort(a+1,a+1+n);
    const int fuck=500000;
    for(int i=0;i<=fuck;i++)
        up[i][0]=i;
        int cur=0;
    for(int i=1;i<=n;i++){
        int j=i;int x=0;
        while(a[j].l==a[i].l&&j<=n){
                x=max(x,a[j].r);
                j++;
        }
        int sub=max(cur,a[i].l)+1;
        for(int k=sub;k<=x;k++){
            up[k][0]=min(up[k][0],a[i].l);
            }
        cur=max(cur,x);
        j--;
        i=j;
    }
 /*   for(int i=0;i<=ma;i++)
        printf("%d ",up[i][0]);
    printf("\n");*/
    for(int i=1;i<=20;i++)
    for(int j=0;j<=fuck;j++){
        up[j][i]=up[up[j][i-1]][i-1];
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(up[y][20]>x){
            printf("-1\n");
            continue;
        }
        int ans=0;
        for(int j=20;j>=0;j--){
            if(up[y][j]>x){
                y=up[y][j];
                ans+=(1<<j);
            }
        }
        ans++;
        printf("%d\n",ans);
    }
}