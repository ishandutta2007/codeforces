#include <iostream>
#include <set>
using namespace std;
int main()
{
	set <int> s;
	int n,i,p,q,num;
	cin >> n >> p;
	for (i=0;i<p;i++)
	{
		cin >> num;
		s.insert(num);
	}
	cin >> q;
	for (i=0;i<q;i++)
	{
		cin >> num;
		s.insert(num);
	}
	if (s.size()==n)
	cout << "I become the guy.";
	else
	cout << "Oh, my keyboard!";
}