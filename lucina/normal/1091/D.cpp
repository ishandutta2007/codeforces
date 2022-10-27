/*
RIP Good Bye 2018
Anyway I like this permutation problem :)
*/

#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10,mod=998244353;
long long n,f[maxn];
int main(){
    scanf("%d",&n);
    f[1]=1;
    f[2]=2;
    long long a=2;
    for(int i=3;i<=n;i++){
        f[i]=(f[i-1]+a-1)*i;
        f[i]=(f[i]+mod)%mod;
        a*=i;
        a%=mod;
    }
    printf("%lld\n",f[n]);
}