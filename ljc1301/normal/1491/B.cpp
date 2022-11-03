#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105;
int n,a[maxn];
ll u,v;
int main()
{
    int T,i;
    bool flag,ok;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld%lld",&n,&u,&v);
        flag=true,ok=false;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=1;i<n;i++) flag&=a[i]==a[0],ok|=abs(a[i]-a[i-1])>=2;
        if(ok) printf("0\n");
        else if(flag) printf("%lld\n",v+min(v,u));
        else printf("%lld\n",min(v,u));
    }
    return 0;
}