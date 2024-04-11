#include <iostream>
#include <set>
using namespace std;
int main()
{
	set <int> s;
	set <int> :: iterator it;
	int n,i,x;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> x;
		s.insert(x);
	}
	if (s.size()==1)
	cout << "NO";
	else
	{
		it=s.begin();
		it++;
		cout << *it;
	}
}