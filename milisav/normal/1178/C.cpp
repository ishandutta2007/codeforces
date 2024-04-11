#include<bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int w,h;
int s;
int main() {
    scanf("%d %d",&w,&h);
    s=w+h;
    long long t = 1;
    for(int i=0;i<s;i++) t=(t*2)%mod;
    printf("%lld",t);
    return 0;
}