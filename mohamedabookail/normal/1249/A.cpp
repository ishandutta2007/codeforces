/**
 *    author:  Mohamed.Abo_Okail
 *    created: 12/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		vector <int> v(n);
		bool b = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for (int i = 1; i < n; i++)
		{
			if(v[i] == v[i - 1] + 1)
				b = 1;
		}

		cout << ((b) ? 2 : 1) << endl;
	}
}