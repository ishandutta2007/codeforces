#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005;
int n;
ll x[maxn],a;
map<ll,int> s;
int main()
{
    int T,i,ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld",&n,&a);
        for(i=0;i<n;i++) scanf("%lld",&x[i]);
        s.clear(),sort(x,x+n),ans=0;
        for(i=0;i<n;i++)
            if(s.count(x[i]) && s[x[i]]) s[x[i]]-=1,ans--;
            else ans++,s[x[i]*a]+=1;
        printf("%d\n",ans);
    }
    return 0;
}