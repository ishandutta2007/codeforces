#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
const int MAXN=200010;
const int INF=1000000000;
int n,a[3],t[MAXN],res,ans=INF,c0,c1,x,y;
multiset<int> S;
int Delete(int x)
{
    multiset<int>::iterator it=S.upper_bound(x);
    if(it==S.begin()) return INF;
    it--;
    int res=(*it);
    S.erase(it);
    return res;
}
void Update(int d,int delta)
{
    if(d<=a[2]) x+=delta;
    if(d<=a[0]+a[1]) y+=delta;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<3;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    sort(a,a+3);
    sort(t+1,t+n+1);
    for(int i=n;i>=1;i--)
    {
        if(t[i]>a[0]+a[1]+a[2]) {puts("-1");return 0;}
        else if(t[i]<=a[0]+a[1]+a[2]&&t[i]>a[1]+a[2]) res++;
        else if(t[i]<=a[1]+a[2]&&t[i]>a[0]+a[2]) res++,c0++;
        else if(t[i]<=a[0]+a[2]&&t[i]>max(a[0]+a[1],a[2])) res++,c1++;
        else
        {
            S.insert(t[i]);
            Update(t[i],1);
        }
    }
    for(int i=1;i<=c0;i++)
    {
        int o=Delete(a[0]);
        Update(o,-1);
    }
    for(int i=1;i<=c1;i++)
    {
        int o=Delete(a[1]);
        Update(o,-1);
    }
    ans=min(ans,res+max(((int)S.size()+1)/2,abs(x-y)));
    for(int i=1;i<=n;i++)
    {
        res++;
        for(int i=0,o;i<3;i++)
            o=Delete(a[i]),Update(o,-1);
        ans=min(ans,res+max(((int)S.size()+1)/2,abs(x-y)));
    }
    printf("%d\n",ans);
    return 0;
}