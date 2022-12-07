#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
const int MAXN=200010;
int n,m;
LL h[MAXN],p[MAXN];
LL L,R=20000000000LL,mid;
bool check()
{
    int cur=1;
    for(int i=1;i<=n;i++)
    {
        if(cur==m+1) return true;
        LL T=mid,pos;
        T-=abs(h[i]-p[cur]);
        if(T<0) continue;
        pos=max(p[cur]+T,h[i]+(T>>1));
        while(cur+1<=m&&p[cur+1]<=pos) cur++;
        cur++;
    }
    if(cur==m+1) return true;
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%I64d",&h[i]);
    for(int i=1;i<=m;i++) scanf("%I64d",&p[i]);
    while(L<R)
    {
        mid=(L+R)>>1;
        if(check()) R=mid;
        else L=mid+1;
    }
    printf("%I64d\n",L);
    return 0;
}