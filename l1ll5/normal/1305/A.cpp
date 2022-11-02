#include <bits/stdc++.h>
#define N 100005
#define ll long long
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
#define mp make_pair
#define pr pair<int,int>
int t,n;
int a[N],b[N],p[N];
int buc[N];
int main()
{
    srand(time(0));
    t=read();
    while(t--)
    {
        n=read();
        for(int i=1;i<=n;i++) a[i]=read();
        for(int i=1;i<=n;i++) b[i]=read();
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
            for(int i=1;i<=n;i++) printf("%d ",a[i]);
            puts("");
            for(int i=1;i<=n;i++) printf("%d ",b[i]);
            puts("");

    }
}