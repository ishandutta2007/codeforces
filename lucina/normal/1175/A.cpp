#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int t;
long long n,k;

int main(){
    scanf("%d",&t);
    while(t--){
            long long ans=0;
        scanf("%lld%lld",&n,&k);
        while(n){
            if(n%k){
                ans+=(n%k);
                n-=(n%k);
            }
            else{
                n/=k;
                ans++;
            }
        }
        printf("%lld\n",ans);
    }
}