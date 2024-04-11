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
	

	int n; cin >> n;
	vector <int> v(n), ans;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n; i++) {
		if(i == (n - 1) || v[i + 1] <= v[i])
			ans.push_back(v[i]);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
}