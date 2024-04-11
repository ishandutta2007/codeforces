#include <iostream>
#include <set>
using namespace std;
#define l 1000001
set <long long> solve()
{
	set <long long> ans;
	int i,x;
	static bool arr[l];
	for (i=2;i*i<l;i++)
	{
		if (arr[i]==false)
		{
			for (x=i*i;x<l;x+=i)
			arr[x]=true;
		}
	}
	for (i=2;i<l;i++)
	{
		if (arr[i]==false)
		ans.insert((long long)i*i);
	}
	return ans;
}
int main()
{
	set <long long> s(solve());
	int n,i;
	long long a;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		if (s.find(a)==s.end())
		cout << "NO" << endl;
		else
		cout << "YES" << endl;
	}
}