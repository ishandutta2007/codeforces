#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 300005
using namespace std;
int n,q;
int a[N],s[N];
int exgcd(int a,int b,int &x,int &y)
{
	if (b==0)
	{
		x=1,y=0;
		return a;
	}
	int z=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return z;
}
void BellaKira()
{
	int sum=0;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		sum+=x;
		a[i]=y-x;
	}
	sort(a+1,a+n+1,greater<int>());
	for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	cin>>q;
	while (q--)
	{
		int x,y;
		cin>>x>>y;
		int ax=0,ay=0;
		int z=exgcd(x,y,ax,ay);
		if (n%z!=0) 
		{
			cout<<-1<<'\n';
			continue;
		}
		x/=z,y/=z;
		ax=(ax*(n/z)%y);
		ax=(ax+y)%y;
		ay=(n/z-x*ax)/y;
		if (ay<0) 
		{
			cout<<-1<<'\n';
			continue;
		}
		int l=0,r=ay/x+1;
		while (l<r-1)
		{
			int mid=(l+r)/2;
			if (s[y*z*(ay-x*(mid-1))]<s[y*z*(ay-x*mid)])
			{
				l=mid;
			} else r=mid;
		}
		cout<<sum+s[y*z*(ay-x*l)]<<'\n';
	}
	
}
signed main()
{
	IOS;cin.tie(0);
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}