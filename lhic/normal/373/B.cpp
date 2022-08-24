#include <iostream>

using namespace std;

typedef long long ll;


ll w,m,k;
ll res=0;

ll dlin(ll a)
{
	ll ans=0;
	while (a>0)
	{
		ans++;
		a/=10;
	}
	return ans;
}


ll step10(ll a)
{
	ll ans=1;
	for (ll i=0;i<a;i++)
		ans*=10;
	return ans;
}



int main()
{
	cin>>w>>m>>k;
	ll dl=dlin(m);
	while ((step10(dl)-m)*dl<=w/k)
	{
		w-=(step10(dl)-m)*dl*k;
		res+=step10(dl)-m;
		m=step10(dl);
		dl=dlin(m);
	}
	res+=w/(dl*k);
	cout<<res;
	return 0;
}