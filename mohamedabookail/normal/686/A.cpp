/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/11/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	
	ll n, x;
	cin >> n >> x;
	int cnt = 0;
	while(n--)
	{
		char ch; ll m;
		cin >> ch >> m;
		if(ch == '+')
			x += m;
		else
		{
			if(x >= m)
				x -= m;
			else
				cnt++;
		}
	}
	cout << x << " " << cnt << endl;
}