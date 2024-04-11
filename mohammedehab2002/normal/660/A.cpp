#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main()
{
	list <int> l;
	list <int> :: iterator it,it2;
	int n,i,res=0;
	cin >> n;
	for (i=0;i<n;i++)
	{
		int a;
		cin >> a;
		l.push_back(a);
	}
	for (it=l.begin(),it2=it;it2!=l.end();it++,it2++)
	{
		if (it2==it)
		it2++;
		if (__gcd(*it,*it2)!=1)
		{
			l.insert(it2,1);
			it++;
			res++;
		}
	}
	cout << res << endl;
	for (it=l.begin();it!=l.end();it++)
	cout << *it << ' ';
}