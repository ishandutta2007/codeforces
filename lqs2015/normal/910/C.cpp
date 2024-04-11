#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
pair<long long,long long> a[11];
long long n,wq,cur,ans;
bool f;
string s;
int main()
{
	cin>>n;
	for (long long i=1;i<=n;i++)
	{
		cin>>s;
		wq=1;
		for (long long j=s.size()-1;j>=0;j--)
		{
			a[s[j]-'a'].first+=wq;
			wq*=10;
			if (!j) a[s[j]-'a'].second=1;
		}
	}
	sort(a,a+10);
	reverse(a,a+10);
	cur=1;
	for (long long i=0;i<10;i++)
	{
		if (!a[i].second && !f) 
		{
			f=1;
			continue;
		}
		ans=ans+cur*a[i].first;
		cur++;
	}
	cout<<ans<<endl;
	return 0;
}