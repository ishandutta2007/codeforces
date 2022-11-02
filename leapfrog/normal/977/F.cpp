//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
using namespace std; const int N=400010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],plc,ot[N],cnt;
map<int,int> Q;
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i]=read();
    for(ri int i=1;i<=n;i++)
    {
        Q[a[i]]=Q[a[i]-1]+1;
    }
    int res=0;
    for(ri int i=n;i;i--)
    {
        if(Q[a[i]]>res) res=Q[a[i]], plc=i;
    }
    for(ri int i=n;i;i--) if(Q[a[i]]==res) { plc=i; break; }
    printf("%lld\n",res);
    int now=a[plc];
    ot[++cnt]=plc;
    for(ri int i=plc-1;i;i--)
    {
        if(a[i]==now-1) ot[++cnt]=i, now--;
    }
    for(ri int i=cnt;i;i--) printf("%lld ",ot[i]);
    puts("");
    return 0;
}