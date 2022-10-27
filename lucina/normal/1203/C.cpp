#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a;
long long g,x;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        g=__gcd(g,x);
    }
    a=(int)sqrt(g);
    int res=1;
    for(int i=2;i<=a;i++){
        if(g%i==0){
            int s=0;
            while(g%i==0){
                g/=i;
                s++;
            }
            res*=(s+1);
        }
    }
    if(g>1){
        res*=(2);
    }
    printf("%d\n",res);
}