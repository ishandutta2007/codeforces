#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector <int> v1,v2,v3;
	int n,i,a;
	cin >> n;
	for (i=0;i<n;i++)
	{
		cin >> a;
		if (a<0)
		v1.push_back(a);
		else if (a>0)
		v2.push_back(a);
		else
		v3.push_back(a);
	}
	if (v2.size()==0)
	{
		for (i=0;i<2;i++)
		{
			v2.push_back(v1.back());
			v1.pop_back();
		}
	}
	if (v1.size()%2==0)
	{
		v3.push_back(v1.back());
		v1.pop_back();
	}
	cout << v1.size();
	for (i=0;i<v1.size();i++)
	cout << " " << v1[i];
	cout << endl << v2.size();
	for (i=0;i<v2.size();i++)
	cout << " " << v2[i];
	cout << endl << v3.size();
	for (i=0;i<v3.size();i++)
	cout << " " << v3[i];
}