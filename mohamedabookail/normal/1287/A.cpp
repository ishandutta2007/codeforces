/**
 *    author:  Mohamed Abo_Okail
 *    created: 16/O1/2O2O
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int t; cin >> t;
	while(t--) {
		string s; int n;
		cin >> n >> s;
		int ans = 0, c = 0;
		for (int i = n - 1; i >= 0; i--) {
			if(s[i] == 'A') {
				ans = max(ans, c);
				c = 0;
				continue;
			}
			c++;
		}
		cout << ans << endl;
	}
}