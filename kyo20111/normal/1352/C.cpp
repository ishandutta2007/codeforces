#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
ll n, k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld",&n,&k);
        printf("%lld\n",k / (n-1) * n + (k % (n-1) ? k % (n-1) : -1));
    }
}