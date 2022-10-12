/**
 *    author:  Mohamed.Abo_Okail
 *    created: 23/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	int ans = 0;
	bool b = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a, b;
			cin >> a >> b;
			if(a || b) { b = 1; }
			if(b) { ans++; b = 0; }
		}
	}
	cout << ans << endl;
}