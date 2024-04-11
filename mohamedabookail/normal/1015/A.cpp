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
	

	int n, k;
	cin >> n >> k;
	vector <int> v(k + 1, 0), ans;

	while(n--) {
		int a, b;
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			v[i] = 1;
		}
	}

	for (int i = 1; i <= k; i++) {
		if(!v[i]) ans.push_back(i);
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}