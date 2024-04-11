#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		string s, t;
		cin >> s >> t;
		bool flag = false;
		vector <int> A(26, 0), B(26, 0);
		for(int j = 0; j < s.size(); j++)
		{
			A[s[j] - 'a']++;
			B[t[j] - 'a']++;
		}
		for(int j = 0; j < 26; j++)
		{
			if(A[j] > 0 && B[j] > 0)
			{
				flag = true;
			}
		}
		if(flag)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
	return 0;
}