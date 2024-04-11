#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
ll a, b, n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld %lld %lld",&a,&b,&n);
        if(a < b) swap(a, b);

        int c = 0;
        while(a <= n){
            ll k = a;
            a += b;
            b = k;
            c++;
        }
        printf("%d\n",c);
    }
}