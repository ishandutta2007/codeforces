#include<bits/stdc++.h>
using namespace std;
const int CONST = pow(2, 30) + 1;
signed main()
{
	string s;
	cin >> s;
	while(s == "start")
	{
		int l = 1, r = 1e9 + 1;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			cout << "? " << l << " " << midd << endl;
			cin >> s;
			if(s == "x")
			{
				r = midd;
			}
			else
			{
				l = midd;
			}
		}
		l++;
		int l1 = l;
		vector <int> A;
		for(int i = 2; i <= sqrt(l); i++)
		{
			while(l1 % i == 0)
			{
				A.push_back(i);
				l1 = l1 / i;
			}
		}
		if(l1 != 1)
		{
			A.push_back(l1);
		}
		for(int i = 0; i < A.size(); i++)
		{
			cout << "? " << l << " " << l / A[i] << endl;
			cin >> s;
			if(s == "x")
			{
				l = l / A[i];
			}
		}
		cout << "! " << l << endl;
		cin >> s;
	}
	return 0;
}