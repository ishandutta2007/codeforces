#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,x,b;
int main(){
    int r=0;
    scanf("%d%d",&b,&k);
    b&=1;
    for(int i=1;i<k;i++){
        scanf("%d",&x);
            r+=((b*(x&1))&1);
            r&=1;
    }
    scanf("%d",&x);
    r+=(x&1);
    r&=1;
    r==0?printf("even"):printf("odd");


}