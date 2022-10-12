/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O2/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define o_o "\n"
#define ll long long

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector < int > v(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	int q; cin >> q;
	while(q--) {
		int a, b; cin >> a >> b;
		v[a - 1] += b - 1;
		v[a + 1] += v[a] - b;
		v[a] = 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << v[i] << o_o;
	}
}