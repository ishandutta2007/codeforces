#include <iostream>
#include <set>
using namespace std;
set <long long> s;
int main()
{
	pair <int,int> p;
	int n;
	long long r=0;
	cin >> n;
	if (n==1)
	{
		cout << 1;
		return 0;
	}
	long long arr[n][n];
	for (int i=0;i<n;i++)
	{
		long long a=0;
		bool z=0;
		for (int x=0;x<n;x++)
		{
			cin >> arr[i][x];
			a+=arr[i][x];
			if (!arr[i][x])
			z=1,p=make_pair(i,x);
		}
		if (z)
		r=a;
		else
		s.insert(a);
	}
	if (s.size()>1)
	cout << -1;
	else
	{
		long long sum=*s.begin(),d=sum-r;
		if (d<=0)
		cout << -1;
		else
		{
			arr[p.first][p.second]=d;
			s.clear();
			for (int i=0;i<n;i++)
			{
				long long a=0;
				for (int x=0;x<n;x++)
				a+=arr[x][i];
				s.insert(a);
			}
			long long c=*s.begin();
			if (s.size()>1 || c!=sum)
			cout << -1;
			else
			{
				long long s1=0,s2=0;
				for (int i=0;i<n;i++)
				s1+=arr[i][i],s2+=arr[i][n-i-1];
				if (s1!=s2 || s1!=c)
				cout << -1;
				else
				cout << d;
			}
		}
	}
}