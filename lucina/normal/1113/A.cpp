#include<bits/stdc++.h>
using namespace std;
int n,v,sum,l,res,f;
int main(){
    scanf("%d%d",&n,&v);
    res=n-1;
    for(int i=1;i<=n;i++){
        f=min(res,v-l);
        sum+=(i*f);
        res-=f;
        l+=f;
        l--;
    }
    printf("%d",sum);
}