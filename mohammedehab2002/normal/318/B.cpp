#include <iostream>
#include <string.h>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	deque <int> a,b;
	long long i,ans=0,tmp;
	string s,t;
	cin >> s;
	if (s.size()<10)
	{
		cout << 0;
		return 0;
	}
	for (i=0;i<s.size()-4;i++)
	{
		t=s.substr(i,5);
		if (t=="heavy")
		a.push_back(i);
		else if (t=="metal")
		b.push_back(i);
	}
	for (i=0;i<a.size();i++)
	{
		tmp=(b.end()-upper_bound(b.begin(),b.end(),a[i]));
		ans+=tmp;
	}
	cout << ans;
}