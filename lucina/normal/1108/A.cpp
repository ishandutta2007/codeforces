#include<bits/stdc++.h>
using namespace std;
int q,l,r,ll,rr;
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d%d%d%d",&l,&r,&ll,&rr);
        printf("%d ",l);
        ll==l?printf("%d\n",l+1):printf("%d\n",ll);
    }
    
}