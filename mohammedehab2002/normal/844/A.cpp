#include <iostream>
#include <set>
using namespace std;
set<int> s;
int main()
{
	string a;
	int k;
	cin >> a >> k;
	for (int i=0;i<a.size();i++)
	s.insert(a[i]);
	if (k>26 || k>a.size())
	cout << "impossible";
	else
	cout << max(k-(int)s.size(),0);
}