#include<bits/stdc++.h>
#define int long long
int n,m,a;
signed main(){
    scanf("%lld%lld%lld",&n,&m,&a);
    printf("%lld",(int)(ceil(n/(double)a)*ceil(m/(double)a)));
}