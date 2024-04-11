#include <iostream>
#include <deque>
using namespace std;
deque <int> v;
int func(int n,int a) {
	int ret=0;
	if (v[a-1]==1)
	ret++;
	if (a-1==n-a)
	return ret;
	if (a-1<n-a)
	{
		deque <int> :: reverse_iterator it;
		for (it=v.rbegin();n-a!=a-1;it++,n--)
		{
			if (*it==1)
			ret++;
			v.pop_back();
		}
	}
	else
	{
		deque <int> :: iterator it;
		for (it=v.begin();n-a!=a-1;it++,a--,n--)
		{
			if (*it==1)
			ret++;
			v.pop_front();
		}
	}
	return ret;
}
int main()
{
	int n,a,i,ans=0;
	cin >> n >> a;
	v.resize(n);
	a--;
	for (i=0;i<n;i++)
	cin >> v[i];
	if (v[a]==1)
	ans++;
	for (i=1;a>=i || a+i<n;i++)
	{
		if (a>=i && a+i<n)
		{
			if (v[a-i]==v[a+i] && v[a-i]==1)
			ans+=2;
		}
		else if (a>=i)
		{
			if (v[a-i]==1)
			ans++;
		}
		else
		{
			if (v[a+i]==1)
			ans++;
		}
	}
	cout << ans;
}