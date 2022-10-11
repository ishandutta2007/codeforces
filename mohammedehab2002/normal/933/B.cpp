#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<long long> v;
int main()
{
	long long p,k,rem;
	cin >> p >> k;
	v.push_back(-p/k);
	for (int i=0;;i++)
	{
		for (long long x=v.back()/k-1;x<=v.back()/k+1;x++)
		{
			if (v.back()-x*k>=0 && v.back()-x*k<k)
			{
				v.push_back(-x);
				break;
			}
		}
		if (v[v.size()-1]*k+v[v.size()-2]<k && v.back()<k && v.back()>=0)
		break;
	}
	while (v.back()==0)
	v.pop_back();
	v.push_back(0);
	cout << v.size() << endl;
	for (int i=0;i<v.size();i++)
	{
		if (i)
		cout << v[i]*k+v[i-1] << ' ';
		else
		cout << v[i]*k+p << ' ';
	}
}