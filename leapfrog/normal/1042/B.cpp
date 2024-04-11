//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define mk make_pair
#define E (n+1)
using namespace std; const int N=2010;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
int n;
int a[10];
string t[]={"","A","B","C","AB","AC","BC","ABC"};
signed main()
{
    cin>>n;
    for(ri int i=0;i<=9;i++) a[i]=1e18;
    for(ri int i=1;i<=n;i++)
    {
        int x;
        string s;
        cin>>x>>s;
        sort(s.begin(),s.end());
        int qwq;
        if(s=="A") qwq=1;
        if(s=="B") qwq=2;
        if(s=="C") qwq=3;
        if(s=="AB") qwq=4;
        if(s=="AC") qwq=5;
        if(s=="BC") qwq=6;
        if(s=="ABC") qwq=7;
        a[qwq]=min(a[qwq],x);
    }
    a[0]=0;
    int res=1e18;
    for(ri int i=0;i<=7;i++)
    {
        for(ri int j=0;j<=7;j++)
        {
            for(ri int k=0;k<=7;k++)
            {
                string p=t[i]+t[j]+t[k];
                sort(p.begin(),p.end());
                int a1,a2,a3;
                a1=a2=a3=0;
                int len=p.length();
                for(ri int x=0;x<len;x++)
                {
                    if(p[x]=='A') a1=1;
                    if(p[x]=='B') a2=1;
                    if(p[x]=='C') a3=1;
                }
                if(a1&&a2&&a3) res=min(res,a[i]+a[j]+a[k]);
            }
        }
    }
    if(res>=1e18) puts("-1");
    else printf("%lld\n",res);
    return 0;
}