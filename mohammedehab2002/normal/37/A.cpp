#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int main()
{
	set <int> t;
	vector <int> v;
	int n,i,maxi=0;
	cin >> n;
	int ans=n;
	v.resize(n);
	for (i=0;i<n;i++)
	cin >> v[i];
	while (v.size())
	{
		if (count(v.begin(),v.end(),v.back())>maxi)
		maxi=count(v.begin(),v.end(),v.back());
		if (t.find(v.back())==t.end())
		ans-=count(v.begin(),v.end(),v.back())-1;
		t.insert(v.back());
		v.pop_back();
	}
	cout << maxi << " " << ans;
}