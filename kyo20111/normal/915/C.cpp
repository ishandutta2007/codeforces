#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a, b, c[10], t, k;
int main(){
    scanf("%lld %lld",&a,&b);
    while(a) c[a%10]++, t++, a/=10;

    while(t--){
        for(int i=9;i>=(k==0);i--) if(c[i]){
            c[i]--;
            ll n = k*10+i;
            for(int j=0;j<=9;j++){
                ll u = 0;
                while(u < c[j]) u++, n=n*10+j;
            }
            c[i]++;
            if(n <= b){
                k = k*10+i;
                c[i]--;
                break;
            }
        }
    }
    printf("%lld",k);
}