#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=110;
typedef long long LL;
int n,a[MAXN];
bool used[MAXN];
LL ans=1;
LL gcd(LL a,LL b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
LL lcm(LL a,LL b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        if(used[a[i]]) {puts("-1");return 0;}
        else used[a[i]]=true;
    for(int i=1;i<=n;i++) used[i]=false;
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            int t=0,x=i;
            while(!used[a[x]])
            {
                x=a[x];
                used[x]=true;
                t++;
            }
            if(t%2==1) ans=lcm(ans,t);
            else ans=lcm(ans,t/2);
        }
    printf("%I64d\n",ans);
    return 0;
}