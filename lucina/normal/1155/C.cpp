#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m;
long long x[maxn],p[maxn],gcd;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
        if(i>1){
        if(gcd==0ll)
        gcd=(x[i]-x[i-1]);
        else
        gcd=__gcd(x[i]-x[i-1],gcd);
    }
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&p[i]);
    }
    for(int i=1;i<=m;i++){
        if(gcd%p[i]==0){
            printf("YES\n");
            printf("%lld %d",x[1],i);
            return 0;
        }
    }
    printf("NO");
    return 0;
}
/*
Lucina
*/