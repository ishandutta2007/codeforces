#include<stdio.h>
int a,b,c,ans;
int main(){
scanf("%d %d %d",&a,&b,&c);
    for(int i=1;i<=c;i++){
        ans+=(2*a+2*b-4);
        a=a-4;
        b=b-4;
    }
    printf("%d\n",ans);
}