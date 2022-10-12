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
	int n, k; cin >> n >> k;
	int cnt = n * (n + 1) / 2;
	k %= cnt;
	if(!k) { cout << 0 << o_o; }
	for (int i = n; i > 0; i--) {
		if((i * (i + 1) / 2) <= k) {
			cout << k - (i * (i + 1) / 2) << o_o;
			break;
		}
	}
}