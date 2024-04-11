#include <iostream>
#include <set>
using namespace std;
int main()
{
	set <int> s;
	int n,i;
	cin >> n;
	for (i=0;i<n;i++)
	{
		int a;
		cin >> a;
		s.insert(a);
	}
	set <int> :: iterator e=s.end(),t=s.begin();
	e--;
	e--;
	t++;
	t++;
	for (set <int> :: iterator it=s.begin();it!=e;it++,t++)
	{
		if (*it+2>=*t)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}