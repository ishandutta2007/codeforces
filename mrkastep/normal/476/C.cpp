#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
using namespace std;

#define For(i,n) for(i=0;i<(n);i++)

void solve(int a){
    const int mod=1000000007;
    long long int b,ans=0,ans1;
    scanf("%I64d",&b);
    ans=ans1=b*(b-1)/2;
    ans%=mod;
    ans1%=mod;
    if(a%2==0) ans*=a;
    else ans*=(a+1);
    ans/=2;
    ans%=mod;
    if(a%2==0) ans*=a+1;
    else ans*=a;
    ans%=mod;
    ans*=b;
    ans%=mod;
    ans+=ans1*a;
    ans%=mod;
    printf("%I64d\n",ans);
}

int main() {
#pragma comment(linker, "/STACK:268435456")
#ifndef     ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k,l;
    while(scanf("%d",&n)!=EOF){
        solve(n);
    }
    return 0;
}