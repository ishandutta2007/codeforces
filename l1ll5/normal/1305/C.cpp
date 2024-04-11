#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
#define fi first
#define se second
#define pr pair<int,int>
int n,m,a[N];
int b[N],ans;
map<int,int> mp;

main()
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)b[i]=a[i]%m;

    for(int i=1;i<=n;i++)
    {
        if(mp[b[i]]!=0)
        {
            puts("0");
            return 0;
        }
        mp[b[i]]++;
    }
    ans=1;
    for(int i=1;i<=n;i++)
    for(int j=1;j<i;j++)
    {
        ans=ans*(a[i]-a[j]);
        if(ans<0) ans=-ans;
        ans%=m;
    }
    cout<<ans<<endl;
}