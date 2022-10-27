#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int q,n,a,b;
long long k;

int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%lld%d%d%d",&k,&n,&a,&b);
        k-=(1LL*b*n);
        k--;
        printf("%lld\n",k<0LL?-1LL:min((long long)n,k/(a-b)));
    }
}