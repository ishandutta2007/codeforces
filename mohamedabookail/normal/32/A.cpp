/**
 *    author:  Mohamed Abo_Okail
 *    created: 25/O1/2O2O
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
	int n, d; cin >> n >> d;
	vector < int > v(n);
	int nemo = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = (i + 1); j < n; j++) {
			if(v[j] - v[i] <= d) {
				nemo += 2;
			}
		}
	}
	cout << nemo << o_o;
}