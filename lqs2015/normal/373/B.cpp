#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long w,m,k,ts,cnt,p,ans;
long long Pow(long long a,long long n)
{
	long long res=1;
	for (int i=1;i<=n;i++)
	res=res*a;
	return res;
}
int main()
{
	cin>>w>>m>>k;
	w/=k;
	ts=m;
	while(ts)
	{
		cnt++;
		ts/=10;
	}
	p=Pow(10,cnt)-m;
	if (p*cnt>=w)
	{
		cout<<w/cnt<<endl;
		return 0;
	}
	w=w-p*cnt;
	ans=p;
	while(1)
	{
		p=9*Pow(10,cnt);
		if (p*(cnt+1)>=w)
		{
			cout<<ans+w/(cnt+1)<<endl;
			return 0;
		}
		ans+=p;
		w=w-p*(cnt+1);
		cnt++;
	}
	return 0;
}