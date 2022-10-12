/**
 *    author:  Mohamed Abo_Okail
 *    created: 26/O1/2O2O
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
	ll nemo = n;
	for (int i = 1; i < n; i++) {
		nemo += (n - i) * i;
	}
	cout << nemo << o_o;
}