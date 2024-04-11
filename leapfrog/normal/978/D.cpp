//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
#define mk make_pair
using namespace std; const int N=500010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,a[N],res=1e18,mx=-1e18,mi=1e18,book[N];
signed main()
{
    n=read();
    for(ri int i=1;i<=n;i++) a[i]=read();
    if(n==1 || n==2)
    {
        puts("0");
        return 0;
    }
    for(ri int i=2;i<=n;i++) mx=max(mx,a[i]-a[i-1]), mi=min(mi,a[i]-a[i-1]);
    if(mx-mi>4) { puts("-1"); return 0; }
    for(ri int i=mi;i<=mx;i++)
    {
        if(abs(a[1]+i*(n-1)-a[n])>2) continue;
        int flg=0;
        for(ri int j=2;j<=n;j++)
        {
            if(abs(a[j]-a[j-1]-i)>2) { flg=1; break; }
        }
        if(flg) continue;
        for(ri int j=-1;j<=1;j++)
        for(ri int k=-1;k<=1;k++)
        {
            int now=0;
            a[1]+=j, a[n]+=k;
            if(abs(a[1]+i*(n-1)-a[n])) { a[1]-=j, a[n]-=k; continue; }
            if(j) now++;
            if(k) now++;
            int qwq=a[1];
            if(abs(a[2]-qwq-i)>1) { a[1]-=j, a[n]-=k; continue; }
            //for(ri int x=1;x<=n;x++) printf("%lld ",a[x]);
            //puts("");
            for(ri int x=2;x<n;x++)
            {
                if(abs(a[x]-qwq-i)>1) { now=1e18; break; }
                if(a[x]!=qwq+i) now++;
                qwq+=i;
            }
            if(abs(a[n]-qwq-i)>1) now=1e18;
            a[1]-=j, a[n]-=k;
            res=min(res,now);
        }
    }
    if(res==1e18) puts("-1");
    else printf("%lld\n",res);
    return 0;
}