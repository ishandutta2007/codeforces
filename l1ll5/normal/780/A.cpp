#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1000005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int a[N],vis[N];
int main()
{
    int n=read();
    int ans = 0,tmp = 0;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<2*n;i++)
    {
        int x=read();
        if(vis[x])
        {
            tmp--;
            vis[x] = 0;
        }
        else
        {
            tmp++;
            ans = max(tmp,ans);
            vis[x] = 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}