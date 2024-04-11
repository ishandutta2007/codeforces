#include <iostream>
#include <math.h>
#include <map>
using namespace std;
map<int,int> m;
int main()
{
	long long a,q,l,n;
	cin >> a >> q >> l >> n;
	for (int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		m[a]=1;
	}
	if (abs(a)>l)
	cout << 0;
	else if (a==0)
	{
		if (m[0])
		cout << 0;
		else
		cout << "inf";
	}
	else if (q==0)
	{
		if (m[a] && m[0])
		cout << 0;
		else if (m[0])
		cout << 1;
		else
		cout << "inf";
	}
	else if (q==1)
	{
		if (m[a])
		cout << 0;
		else
		cout << "inf";
	}
	else if (q==-1)
	{
		if (m[a] && m[-a])
		cout << 0;
		else
		cout << "inf";
	}
	else
	{
		int ans=0;
		while (abs(a)<=l)
		ans+=!m[a],a*=q;
		cout << ans;
	}
}