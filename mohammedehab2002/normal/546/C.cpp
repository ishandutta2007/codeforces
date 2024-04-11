#include <iostream>
#include <queue>
using namespace std;
int main()
{
	queue <int> s1,s2;
	int tmp,n,ans=0,c1,c2,i;
	cin >> tmp >> n;
	for (i=0;i<n;i++)
	{
		cin >> tmp;
		s1.push(tmp);
	}
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> tmp;
		s2.push(tmp);
	}
	while (s1.size() && s2.size())
	{
		c1=s1.front();
		c2=s2.front();
		s1.pop();
		s2.pop();
		if (c1>c2)
		{
			s1.push(c2);
			s1.push(c1);
		}
		else
		{
			s2.push(c1);
			s2.push(c2);
		}
		ans++;
		if (ans>100000)
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans << " ";
	if (s1.size())
	cout << 1;
	else
	cout << 2;
}