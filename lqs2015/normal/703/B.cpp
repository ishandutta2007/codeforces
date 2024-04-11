#include<iostream>
#include<set>
using namespace std;
long long n,k,x,c[111111],sum,ans,sumc,summ;
set<int> s;
int main()
{
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>c[i];
		sum+=c[i];
	} 
	for (int i=1;i<=k;i++)
	{
		cin>>x;
		s.insert(x); 
		sumc+=c[x];
		ans=ans+c[x]*(sum-c[x]);
	}
	for (int i=1;i<=n;i++)
	{
		int next=i%n+1;
		bool f=s.find(i)!=s.end(),f1=s.find(next)!=s.end();
		if (f || f1) continue;
		ans=ans+c[i]*c[next];
	}
	for (set<int>::iterator it=s.begin();it!=s.end();it++)
	{
		long long t=c[*it];
		summ=summ+t*(sumc-t);
	}
	summ/=2;
	ans-=summ;
	cout<<ans<<endl;
	return 0;
}