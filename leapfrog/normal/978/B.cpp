//xtwakioi! xtwddYnoi()!
#include <bits/stdc++.h>
#define ri register
#define int long long
#define E (n+1)
#define mk make_pair
using namespace std;
inline int read()
{
    int s=0, w=1; ri char ch=getchar();
    while(ch<'0'||ch>'9') { if(ch=='-') w=-1; ch=getchar(); }
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar();
    return s*w;
}
string s;
int res;
signed main()
{
    int n=read();
    cin>>s;
    int now=0;
    for(ri int i=0;i<n;i++)
    {
        if(s[i]!='x')
        {
            res+=max(0ll,now-2);
            now=0;
        }
        else
        {
            now++;
        }
    }
    printf("%lld\n",res+max(0ll,now-2));
    return 0;
}