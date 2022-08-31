#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int a,n;
string s;

void init()
{
	cin>>a>>s;
	s="+"+s;
	n=s.length();
}

vector<int> v;

void work()
{
	int ans=0;
	for (int i=0;i<n;i+=3)
	{
		int flag=(s[i++]=='+')?1:-1;
		int x=0;
		if ('0'<=s[i]&&s[i]<='9')
		{
			while ('0'<=s[i]&&s[i]<='9')
				x=x*10+s[i++]-'0';
			++i;
		}
		else
			x=1;
		x=x*flag;
		v.push_back(x);
		ans+=a*x;
		if (s[i]=='a')
			ans-=x;
	}
	sort(v.begin(),v.end());
	for (int i=0;i<v.size();++i)
		ans+=(i+1)*v[i];
	cout<<ans<<endl;
}

int main()
{
	init();
	work();
	return 0;
}