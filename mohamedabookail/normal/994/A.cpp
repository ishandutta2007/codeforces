/**
 *    author:  Mohamed.Abo_Okail
 *    created: 24/11/2019
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
	vector <int> a(n), b(m), ans;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(a[i] == b[j])
				ans.push_back(b[j]);
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}