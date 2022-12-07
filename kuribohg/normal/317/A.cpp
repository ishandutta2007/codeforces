#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL x,y,m,ans;
int main()
{
    cin>>x>>y>>m;
    if(max(x,y)>=m) {puts("0");return 0;}
    if(x>y) swap(x,y);
    if(y<=0) {puts("-1");return 0;}
    ans=-x/y;
    x+=ans*y;
    if(x<0) ans++,x+=y;
    while(max(x,y)<m)
    {
        if(x>y) swap(x,y);
        x+=y,ans++;
    }
    cout<<ans<<endl;
    return 0;
}