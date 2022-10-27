#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a;

 main(){
    scanf("%lld%lld%lld",&n,&m,&a);
    int x=(n/a+(n%a!=0));
    printf("%lld\n",x*(m/a+(m%a!=0)));
    
}