/**
 *    author:  Mohamed.Abo_Okail
 *    created: 08/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	//freopen("in.in", "r", stdin);
	//freopen("out.out", "w", stdout);
	
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		string a, b;
		cin >> a >> b;
		set <char> st1, st2;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if(a[i] != b[i])
			{
				cnt++;
				st1.insert(a[i]);
				st2.insert(b[i]);
			}
		}
		if(cnt == 2 && st1.size() == 1 && st2.size() == 1)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

	}
}