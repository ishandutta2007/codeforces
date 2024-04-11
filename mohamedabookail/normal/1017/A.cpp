/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	int t; cin >> t;
	vector <int> v(t);
	int ans = 0, cntb = 1;
	for(int i = 0; i < t; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		v[i] = (a + b + c + d);
		
	}
	ans = v[0];
	sort(v.begin(), v.end());
	if(ans == v[t - 1])
		return cout << cntb << endl, 0;
	for (int i = (t - 2); i >= 0; i--) 
	{
	    cntb++;
		if(ans == v[i]) break;
	}
	cout << cntb << endl;
}