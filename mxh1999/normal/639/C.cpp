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

#define maxn 200010
ll a[maxn],b[maxn*10];
ll n,k;

int main()
{
	read(n),read(k);
	for (int i=0;i<=n;i++)	read(a[i]),b[i]=a[i];
	ll m=0;
	for (int i=0;i<=n;i++)
	{
		b[i]+=m;
		if (b[i]%2==0)	m=b[i]/2,b[i]=0;else
		if (i==n && b[i]==-1)	b[i]=-1,m=0;else
		{
			m=(b[i]-1)/2;
			b[i]=1;
		}
		//while (b[i]<0)	b[i]+=2,m--;
	}
	int len=n;
	while (m!=0)
	{
		len++;
		if (m%2==0)
		{
			b[len]=0;
			m=m/2;
		}	else
		{
			if (m==-1)	b[len]=-1,m=0;else	m=(m-1)/2,b[len]=1;
		}
		//while (b[len]<0)	b[len]+=2,m--;
	}
	int pos=0;
	while (b[pos]==0)	pos++;
	ll now=0;
	int mjy=0;
	for (int i=len;i>=0;i--)
	{
		now=now*2+b[i];
		if (abs(now)>2*k)	break;
		if (i<=n && i<=pos)
		if (abs(-now+a[i])<=k)
		if (i!=n || a[i]-now!=0)	mjy++;
	}
	printf("%d\n",mjy);
	return 0;
}