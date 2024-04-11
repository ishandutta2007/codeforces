#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
ll a[1<<17];
ll b,q,l;
int n;
bool flag0,flag1,flagb,flagbb;
bool c(ll s)
{
	return upper_bound(a,a+n,s)==lower_bound(a,a+n,s);
}
main()
{
	cin>>b>>q>>l>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)flag0=1;
		else if(a[i]==1)flag1=1;
		if(a[i]==b)flagb=1;
		if(a[i]==-b)flagbb=1;
	}
	if(abs(b)>l)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(b==0)
	{
		cout<<(flag0?"0":"inf")<<endl;
		return 0;
	}
	if(q==0)
	{
		cout<<(flag0?flagb?"0":"1":"inf")<<endl;
		return 0;
	}
	if(q==1)
	{
		cout<<(flagb?"0":"inf")<<endl;
		return 0;
	}
	if(q==-1)
	{
		cout<<(flagb&&flagbb?"0":"inf")<<endl;
		return 0;
	}
	sort(a,a+n);
	ll cnt=0;
	while(abs(b)<=l)
	{
		cnt+=c(b);
		b*=q;
	}
	cout<<cnt<<endl;
}