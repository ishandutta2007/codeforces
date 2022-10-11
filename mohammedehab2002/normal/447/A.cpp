#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	vector <int> v;
	int n,p,x,i;
	cin >> p >> n;
	for (i=0;i<n;i++)
	{
		cin >> x;
		if (find(v.begin(),v.end(),x%p)!=v.end())
		{
			cout << i+1;
			return 0;
		}
		v.push_back(x%p);
	}
	cout << -1;
}