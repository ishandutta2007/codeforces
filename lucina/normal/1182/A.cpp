#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n;
long long ans;

int main(){
    scanf("%d",&n);
    if(n&1)return !printf("0");
    ans=(1LL<<(n/2));
    printf("%lld\n",ans);
}