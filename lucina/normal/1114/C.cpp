#include<bits/stdc++.h>
using namespace std;
long long n,b,a,c,m,r;
int main(){
    scanf("%lld%lld",&n,&b);
    long long ans=1e18;
    for(int i=2;i<=(1e6)+5;i++){
        if(b==1)
        break;
        if(b%i==0){
            c=0;
            while(b%i==0){
                c++;
                b/=i;
            }
            r=0;m=1;
            while(n/i>=m){
                m*=i;
                r+=(n/m);
            }
            ans=min(ans,r/c);
        }
    }
    if(b>1){
        r=0;m=1;
        while(n/b>=m){
            m*=b;
            r+=(n/m);
        }
        ans=min(ans,r);

    }
    printf("%lld\n",ans);
}