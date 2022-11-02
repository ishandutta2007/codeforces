#include<cstdio>
using namespace std;
const int N=200002;
int a[N],T,n,i,j,k,x,y;
void calc(){
    for(k=30;k>=0;k--){
        x=y=0;
        for(i=1;i<=n;i++)
            if(a[i]>>k){
                x++;
                a[i]-=1<<k;
            }
            else
                y++;
        if(x%2){
            if(x%4==3&&y%2==0)
                printf("LOSE\n");
            else
                printf("WIN\n");
            return;
        }
    }
    printf("DRAW\n");
}
int main(){
    scanf("%d",&T);
    while(T--){
        x=y=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",a+i);
        calc();
    }
}