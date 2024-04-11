#include <iostream>
#include <vector>
using namespace std;
int fact(int n,int m)
{
	int ret=0;
	while (n%m==0)
	{
		n/=m;
		ret++;
	}
	return ret;
}
int main()
{
	vector <int> v;
	long long n=1;
	int m,n2=0,n5=0,ans=0;
	cin >> m;
	while (min(n2,n5)<=m)
	{
		n2+=fact(n,2);
		n5+=fact(n,5);
		if (min(n2,n5)==m)
		{
			ans++;
			v.push_back(n);
		}
		n++;
	}
	cout << ans << endl;
	for (int i=0;i<v.size();i++)
	cout << v[i] << ' ';
}