/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		ans += a;
	}
	cout << fixed << setprecision(12) << double(ans) / n << endl;
}