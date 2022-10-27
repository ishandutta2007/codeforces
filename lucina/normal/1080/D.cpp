#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int ooo;
long long k,n,p4,k1,id,len;
int main(){
    scanf("%d",&ooo);
    for(int oo=1;oo<=ooo;oo++){
        scanf("%lld%lld",&n,&k);
        if(n==2&&k==3){
            printf("No\n");
            continue;
        }
        p4=1;
        k1=k;
        for(int i=1;i<=n;i++){
            k1-=p4;
            p4*=4;
            if(k1<0)
                break;
        }
        if(k1>0){
            printf("No\n");
            continue;
        }
        else{
            printf("Yes ");
            k--;
            id=1,len=1;
            while(k>=4*len-1&&id<n){
                k-=(4*len-1);
                len*=2;
                id++;
            }
            printf("%d\n",n-id);
        }
        }
}