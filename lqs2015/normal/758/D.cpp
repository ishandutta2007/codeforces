#include<iostream>
#include<string>
using namespace std;
string s;
long long n,cur,ans,mul,last;
int main()
{
	cin>>n>>s;
	last=s.size()-1;
	mul=1;
	while(last>=0)
	{
		for (int i=0;i<=last;i++)
		{
			if (s[i]=='0' && i!=last) continue;
			cur=0;
			for (int j=i;j<=last;j++)
			{
				cur=cur*10+(s[j]-'0');
				if (cur>=n) break;
			}
			if (cur<n)
			{
				ans=ans+mul*cur;
				mul*=n;
				last=i-1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}