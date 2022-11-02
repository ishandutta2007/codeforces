#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(ll &digit)
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
#define maxn 1000010
ll f[maxn][2],a[maxn];
ll n,m;
ll mjy;

int main()
{
	read(n);
	//for (int i=1;i<=n;i++)	read(a[i]);
	for (int i=1;i<=n;i++)	scanf("%I64d",&a[i]);
	a[n+1]=1<<30;
	for (int i=1;i<=n;i++)
	{
		if (i!=1)
		{
			ll num=min(a[i-1],a[i]);
			ll num2=min(a[i],a[i+1]);
			if (num<=num2)	f[i][1]=(f[i][1]+f[i-1][1]*(num-1))%mo;
			else f[i][0]=(f[i][0]+f[i-1][1]*(num-num2))%mo,f[i][1]=(f[i][1]+f[i-1][1]*(num2-1))%mo;
		}
		ll num=min(a[i+1],a[i]);
		f[i][0]=(f[i][0]+a[i]-num)%mo;
		f[i][1]=(f[i][1]+num-1)%mo;
		mjy=(mjy+f[i][0]+f[i][1])%mo;
	}
	cout<<mjy<<endl;
	return 0;
}