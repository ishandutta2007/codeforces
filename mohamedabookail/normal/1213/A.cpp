/**
 *    author:  Mohamed Abo_Okail
 *    created: 11/O2/2O2O
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
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		(oo % 2) ? a++ : b++;
	}
	cout << min(a, b) << o_o;
}