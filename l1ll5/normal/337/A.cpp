#include <bits/stdc++.h>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[N],tmp,ans;
int main()
{
    int n,m;
    n=read(),m=read();
    for(int i=0;i<m;i++)a[i]=read();
    sort(a,a+m);
    int ans=a[n-1]-a[0];

    for(int i=1;i<=m-n;i++)
    {
        ans=min(a[i+n-1]-a[i],ans);
    }
    cout<<ans<<endl;

}