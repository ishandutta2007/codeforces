/**
 *    author:  Mohamed.Abo_Okail
 *    created: 02/01/2020
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; string s; cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == '-') {
		  ans--;
		}
		else {
		  ans++;
		}
		ans = max(ans, 0);
	}
	cout << ans << endl;
}