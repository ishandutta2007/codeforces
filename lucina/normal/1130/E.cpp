#include<bits/stdc++.h>
using namespace std;
int s,n,r;

int main(){
    scanf("%d",&s);
    n=2000;
    printf("%d\n",n);
    s+=2000;
    r=s/1998;
    printf("-1 ");
    for(int i=1;i<=1998;i++){
        printf("%d ",r);
    }
    printf("%d ",s-r*1998);
}