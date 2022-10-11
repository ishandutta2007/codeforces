#include <iostream>
#include <vector>
using namespace std;
vector <int> v;
bool is_prime(int i)
{
	for (int x=2;x*x<=i;x++)
	{
		if (i%x==0)
		return false;
	}
	return true;
}
int main()
{
	int n,k;
	cin >> n >> k;
	v.push_back(2);
	for (int i=3;i+v.back()<n;i++)
	{
		if (is_prime(i))
		v.push_back(i);
	}
	for (int i=1;i<v.size();i++)
	{
		if (is_prime(v[i]+v[i-1]+1))
		k--;
	}
	if (k<=0)
	cout << "YES";
	else
	cout << "NO";
}