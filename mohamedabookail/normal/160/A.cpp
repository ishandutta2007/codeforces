/**
 *    author:  Mohamed Abo_Okail
 *    created: O5/O2/2O2O
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
	vector < int > v(n);
	ll sum = 0, cnt = 0, nemo = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	for (int i = n - 1; i >= 0; i--) {
		cnt += v[i];
		sum -= v[i];
		nemo++;
		if(cnt > sum) break;
	}
	cout << nemo << o_o;
}