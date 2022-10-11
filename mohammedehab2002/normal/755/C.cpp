#include <iostream>
#include <set>
using namespace std;
int main()
{
	int n,a=0;
	set<int> s;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		if (i==x)
		a++;
		else
		s.insert(x);
	}
	cout << a+s.size()/2;
}