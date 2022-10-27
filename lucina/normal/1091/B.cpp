#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,l,r;
int main(){
    cin>>n;
    long long x=0,y=0;
    for(int i=1;i<=2*n;i++){
        scanf("%d %d",&l,&r);
        x+=l;
        y+=r;
    }
    x=x/n;
    y=y/n;
    printf("%lld %lld",x,y);


}