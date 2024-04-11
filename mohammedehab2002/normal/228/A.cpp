#include <iostream>
#include <set>
using namespace std;
int main()
{
	set <int> s;
	int i,a;
	for (i=0;i<4;i++)
	{
		cin >> a;
		s.insert(a);
	}
	cout << 4-s.size();
}