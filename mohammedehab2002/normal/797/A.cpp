#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
	int n,k;
	cin >> n >> k;
	for (int i=2;i*i<=n;i++)
	{
		while (n%i==0)
		{
			v.push_back(i);
			n/=i;
		}
	}
	if (n!=1)
	v.push_back(n);
	if (v.size()<k)
	cout << -1;
	else
	{
		while (v.size()!=k)
		{
			int x=v.back();
			v.pop_back();
			v[v.size()-1]*=x;
		}
		for (int i=0;i<k;i++)
		cout << v[i] << ' ';
	}
}