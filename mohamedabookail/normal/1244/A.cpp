/**
 *    author:  Mohamed.Abo_Okail
 *    created: 05/11/2019
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
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int cnt1 = 0, cnt2 = 0;
		cnt1 = a / c; if(a % c) cnt1++;
		cnt2 = b / d; if(b % d) cnt2++;
		if(cnt1 + cnt2 <= k)
			cout << cnt1 << " " << cnt2 << endl;
		else
			cout << - 1 << endl;
	}
	
}