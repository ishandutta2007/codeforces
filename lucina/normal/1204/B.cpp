#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,l,r;
long long ma,mi,b;

int main(){
    scanf("%d%d%d",&n,&l,&r);
    long long a=1LL;
    b+=1;
    for(int i=1;i<=l;i++){
        mi+=(1LL<<(i-1));
    }
    int res=n-l;
    mi+=res;
    for(int i=1;i<=r;i++){
        ma+=(1LL<<(i-1));
    }
    res=n-r;
    ma+=((1LL<<(r-1))*res);
    printf("%lld %lld\n",mi,ma);
}
/*
    Good Luck
        -Lucina
*/