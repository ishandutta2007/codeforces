#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(register int i=0;i<a.size();++i)
inline ll rd()
{
	char c=getchar();ll x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=200005;
int n,c[N],a[N],f[45][N];
inline int id(ll x)
{
    if(a[1]<x)return 0;
    if(a[n]>=x)return n;
    int l=1,r=n;
    while(r-l>1)
    {
        int m=(l+r)>>1;
        if(a[m]>=x)l=m;else r=m;
    }
    return l;
}
int main()
{
    int T=rd();
    while(T--)
    {
        n=rd();
        rep(i,1,n)a[i]=rd();
        reverse(a+1,a+n+1);
        c[n]=1;
        per(i,n-1,1)c[i]=(a[i]==a[i+1])?c[i+1]+1:1;
        int ans=max(2,c[1]);
        rep(i,2,n)ans=max(ans,c[i]+1);
        rep(i,1,n-1)if(a[i]!=a[i+1])
        {
            int res=c[i+1]+1;
            int x=a[i+1],y=a[i],p=i;
            while(true)
            {
                int t=id(2*y-x);
                if(t)p=t,y=a[p],res++;
                else break;
            }
            ans=max(ans,res);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}