#include<bits/stdc++.h>
using namespace std;

signed main()
{
	string s;
	cin >> s;
	int n = s.size();
	int it1 = 0;
	int it2 = n - 1;
	vector <int> mass;
	while(it1 < it2)
	{
		while(it1 < n && s[it1] != '(')
		{
			it1++;
		}
		while(it2 >= 0 && s[it2] != ')')
		{
			it2--;
		}
		if(it1 < it2)
		{
			mass.push_back(it1);
			mass.push_back(it2);
			it1++;
			it2--;
		}
	}
	if(mass.size() == 0)
	{
		cout << 0;
	}
	else
	{
		cout << 1 << "\n";
		cout << mass.size() << "\n";
		sort(mass.begin(), mass.end());
		for(int i = 0;i < mass.size(); i++)
		{
			cout << mass[i] + 1 << " ";
		}
	}
    return 0;
}