/**
 *    author:  Mohamed.Abo_Okail
 *    created: 30/10/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("distinct.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	int t; cin >> t;
	while(t--)
	{
		string a, b;
		cin >> a >> b;
		bool bo = false;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				if(a[i] == b[j]) bo = true;
			}
		}
		cout << ((bo) ? "YES" : "NO") << endl;
	}
}