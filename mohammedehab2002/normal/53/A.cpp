#include <iostream>
#include <string.h>
#include <set>
#include <stdlib.h>
using namespace std;
int main()
{
	set <string> p;
	set <string> :: iterator it;
	string s,a,k;
	int n,i;
	size_t found;
	cin >> s >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		p.insert(a);
	}
	for (it=p.begin();it!=p.end();it++)
	{
		k=*it;
		found=k.find(s);
		if (found==0)
		{
			cout << k;
			exit(0);
		}
	}
	cout << s;
}