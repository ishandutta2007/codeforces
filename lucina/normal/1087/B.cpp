#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long n,k,x,a;
int main(){
    cin>>n>>k;
    a=n*k;
    for(int i=k-1;i>=1;i--){
        if(a%i==0){
            long long t=a/i;
            x=t+i;
            if(x%k==i){
                printf("%lld\n",x);
                return 0;
            }
        }
    }



}