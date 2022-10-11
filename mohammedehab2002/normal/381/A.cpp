#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int main()
{
	deque <int> a;
	int n,i,turn=0,n1=0,n2=0,tmp;
	cin >> n;
	a.resize(n);
	for (i=0;i<n;i++)
	cin >> a[i];
	while (a.size())
	{
		if (turn%2)
		{
			tmp=max(a.front(),a.back());
			n2+=tmp;
			if (tmp==a.front())
			a.pop_front();
			else
			a.pop_back();
		}
		else
		{
			tmp=max(a.front(),a.back());
			n1+=tmp;
			if (tmp==a.front())
			a.pop_front();
			else
			a.pop_back();
		}
		turn++;
	}
	cout << n1 << " " << n2;
}