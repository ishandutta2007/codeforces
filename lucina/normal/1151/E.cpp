#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,x,y;
long long sum=0;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        if(x>=y)
            sum+=(1ll)*(x-y)*(n-x+1);
        else
            sum+=(1ll)*(y-x)*x;
            y=x;
        }
    printf("%lld\n",sum);
}