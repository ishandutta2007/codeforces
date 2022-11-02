#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
void read(int &digit)
{
	digit=0;
	char c;
	for (c=getchar();(c<'0' || c>'9') && c!='-';c=getchar());
	bool type=false;
	if (c=='-')
		type=true,c=getchar();
	for (;c>='0' && c<='9';digit=digit*10+c-'0',c=getchar());
	if (type==true)
		digit=-digit;
}

const ll mo=1000000007;
#define maxn 200010
ll b[maxn];
ll c[maxn];
int n;
ll rev[maxn];

ll powmod(ll a,ll b)
{
	ll ans=1;
	while (b)
	{
		if (b&1)	ans=(ans*a)%mo;
		a=(a*a)%mo;
		b>>=1;
	}
	return ans;
}
int main()
{
	read(n);
	for (int i=1;i<=n;i++)	rev[i]=powmod(1LL*i,mo-2);
	if (n==1)	b[1]=1;else
	if (n==2)	b[1]=1,b[2]=1;else
	if (n==3)	b[1]=1,b[2]=2,b[3]=mo-1;else
	if (n==4)	b[1]=1,b[2]=mo-1,b[3]=1,b[4]=mo-1;else
	{
		if (n%4==1)
		{
			int q=(n+1)/2;
			q--;
			int qaq=1;
			ll ha=1;
			b[1]=ha;
			for (int i=1;i<=q;i++)
			{
				qaq+=2;
				ha=(ha*(q-i+1))%mo;
				ha=(ha*rev[i])%mo;
				b[qaq]=ha;
			}
		}	else
		if (n%4==2)
		{
			int q=n/2;
			q--;
			int qaq=1;
			ll ha=1;
			b[1]=ha;
			for (int i=1;i<=q;i++)
			{
				qaq+=2;
				ha=(ha*(q-i+1))%mo;
				ha=(ha*rev[i])%mo;
				b[qaq]=ha;
			}
			for (int i=2;i<=n;i+=2)	b[i]=b[i-1];
		}	else
		if (n%4==0)
		{
			int q=n/2;
			q--;
			int qaq=1;
			ll ha=1;
			b[1]=ha;
			for (int i=1;i<=q;i++)
			{
				qaq+=2;
				ha=(ha*(q-i+1))%mo;
				ha=(ha*rev[i])%mo;
				b[qaq]=ha;
			}
			for (int i=2;i<=n;i+=2)	b[i]=mo-b[i-1];
		}	else
		{
			int q=(n-1)/2;
			q--;
			int qaq=1;
			ll ha=1;
			c[1]=ha;
			for (int i=1;i<=q;i++)
			{
				qaq+=2;
				ha=(ha*(q-i+1))%mo;
				ha=(ha*rev[i])%mo;
				c[qaq]=ha;
			}
			for (int i=2;i<=n-1;i+=2)	c[i]=c[i-1];
			for (int i=1;i<=n;i++)
			if (i%2==0)	b[i]=(c[i]+c[i-1])%mo;else b[i]=(c[i]-c[i-1]+mo)%mo;
		}
	}
	//for (int i=1;i<=n;i++)	printf("%d ",b[i]);
	//return 0;
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		int qaq;
		read(qaq);
		ll haha=qaq;
		ans=(ans+(haha*b[i])%mo)%mo;
	}
	cout<<ans<<endl;
	return 0;
}