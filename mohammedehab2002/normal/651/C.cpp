#include <iostream>
#include <map>
using namespace std;
map <pair<int,int>,int> m;
map <int,int> m1,m2;
int main()
{
	int n;
	long long ans=0;
	cin >> n;
	pair <int,int> p[n];
	for (int i=0;i<n;i++)
	{
		cin >> p[i].first >> p[i].second;
		m1[p[i].first]++;
		m2[p[i].second]++;
		m[p[i]]++;
	}
	for (int i=0;i<n;i++)
	{
		ans+=m1[p[i].first]+m2[p[i].second]-2-(m[p[i]]-1);
	}
	cout << ans/2;
}