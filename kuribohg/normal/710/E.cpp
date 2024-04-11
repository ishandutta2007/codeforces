#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int n,x,y;
LL f[10000010];
int main()
{
    scanf("%d%d%d",&n,&x,&y);
    f[1]=x;
    for(int i=2;i<=n;i++)
        f[i]=min(f[i-1]+x,f[(i+1)/2]+y+(i&1)*x);
    cout<<f[n]<<endl;
    return 0;
}