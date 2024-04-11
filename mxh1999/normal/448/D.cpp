#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
int n,m;
ll x;

int main()
{
	cin>>n>>m;
	cin>>x;
	//x=(ll)n*(ll)m-x;
	ll l=1,r=(ll)n*(ll)m;
	while (l<r)
	{
		ll mid=(l+r)/2+(l+r)%2;
		ll ans=0;
		for (int i=1;i<=n;i++)
		{
			ll q=(mid-1)/i;
			if (q>m)	q=m;
			ans+=q;
		}
		if (ans>=x)	r=mid-1;else l=mid;
	}
	cout<<l<<endl;
	return 0;
}