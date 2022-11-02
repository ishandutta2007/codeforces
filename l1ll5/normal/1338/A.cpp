#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100005
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int t;
int n;
int a[N];
main()
{
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;i++) a[i]=read();

        int mx=-1000000001;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            mx=max(mx,a[i]);

            if(mx==a[i]) continue ;

            int t=2,q=1;
            while(t-1<mx-a[i])
            {
                t<<=1;
                q++;
            }

            ans=max(ans,q);
        }
        printf("%lld\n",ans);
    }
}