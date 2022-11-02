//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
#define mk make_pair
using namespace std; const int N=100010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n,m,book[N],f[N];
struct Node { int s,d,c,id; }q[N];
inline bool cp(Node x,Node y) { return x.d<y.d; }
signed main()
{
    n=read(), m=read();
    for(ri int i=1;i<=m;i++) q[i].s=read(), q[i].d=read(), q[i].c=read(), f[q[i].d]=1, q[i].id=i;
    sort(q+1,q+1+m,cp);
    for(ri int i=1;i<=m;i++)
    {
        if(q[i].d==q[i-1].d) { puts("-1"); return 0; }
        int now=0;
        for(ri int j=q[i].s;j<q[i].d;j++)
        {
            if(!book[j] && !f[j]) book[j]=q[i].id, now++;
            if(now>=q[i].c) break;
        }
        if(now<q[i].c) { puts("-1"); return 0; }
        book[q[i].d]=m+1;
    }
    for(ri int i=1;i<=n;i++) printf("%lld ",book[i]);
    puts("");
    return 0;
}