/**
 *    author:  Mohamed.Abo_Okail
 *    created: 20/11/2019
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
		string s; cin >> s;
		bool bl = 0;
		for (int i = 0; i < (n - 10); i++)
		{
			if(s[i] == '8')
				bl = 1;
		}

		cout << ((bl) ? "YES" : "NO") << endl;
	}
}