#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T>
void read(T &num)
{
    num = 0;
    int w = 1;
    char ch = getchar();
    if (ch == '-') w=-1;
    while(ch<'0'||ch>'9')
    {
        ch=getchar();
        if(ch=='-') w = -1;
    }
    while ((ch >= '0' && ch <= '9')) num=num*10+ch-'0',ch=getchar();
    num=num*w;
}
template <typename T, typename... Args>
void read(T &num, Args &... args) { read(num), read(args...); }
const ll N=1e5;
ll f[N+5];
ll a[N+5],c[N+5],t,d,n,m;
bool cmp(ll a,ll b)
{
	if(c[a]!=c[b]) return c[a]<c[b];
	return a<b;
}
int main() 
{
	read(n,m);
	for(ll i=1;i<=n;i++) read(a[i]);
	for(ll i=1;i<=n;i++) read(c[i]);
	for(ll i=1;i<=n;i++) f[i]=i;
	ll cnt=1;
	sort(f+1,f+n+1,cmp);
	for(ll i=1;i<=m;i++)
	{
		read(t,d);
		ll sum=0;
		if(a[t]>=d)
		{
			a[t]-=d;
			sum+=c[t]*d;
			d=0;
		}
		else
		{
			d-=a[t];
			sum+=a[t]*c[t];
			a[t]=0;
		}
		
		while(cnt<=n)
		{
			if(a[f[cnt]]>d)
			{
				a[f[cnt]]-=d;
				sum+=d*c[f[cnt]];
				d=0;
				break;
			}
			else
			{
				d-=a[f[cnt]];
				sum+=a[f[cnt]]*c[f[cnt]];
				a[f[cnt]]=0;
				cnt++;
			}
		}
		if(d!=0) printf("0\n");
		else printf("%lld\n",sum);
	}
	return 0;
}