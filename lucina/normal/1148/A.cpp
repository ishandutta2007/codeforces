#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int x,y,z,b;
long long ans;

int main(){
    scanf("%d%d%d",&x,&y,&z);
    ans+=(z*2);
    ans+=(2*min(x,y));
    b=min(x,y);
    x-=b,y-=b;
    if(x||y)ans++;
    printf("%lld\n",ans);
}