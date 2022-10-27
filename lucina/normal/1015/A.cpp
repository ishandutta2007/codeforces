#include<stdio.h>
int n,a,l,r,b[200],c[200];
int main(){
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&l,&r);
        for(int j=l;j<=r;j++){
            b[j]=1;
        }
    }
    l=0;
    r=1;
    for(int i=1;i<=a;i++){
        if(b[i]==0)
            c[r++]=i;
    }
    printf("%d\n",r-1);
    for(int i=1;i<r;i++){
        printf("%d ",c[i]);
    }

}