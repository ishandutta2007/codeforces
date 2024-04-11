/**
 *    author:  Mohamed Abo_Okail
 *    created: 1O/O2/2O2O
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
	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		int sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			int oo; cin >> oo;
			if(!oo) cnt++;
			sum += oo;
		}
		cout << (sum + cnt != 0 ? cnt : ++cnt) << o_o;
	}
}