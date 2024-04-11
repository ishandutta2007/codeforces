/**
 *    author:  Mohamed Abo_Okail
 *    created: 29/O1/2O2O
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
	int a, b; cin >> a >> b;
	if(a == b) {
		cout << a * 10 << ' ' << b * 10 + 1 << o_o;
	}
	else if(a + 1 == b) {
		cout << a * 10 + 9 << ' ' << b * 10 << o_o;
	}
	else if(a == 9 && b == 1) {
		cout << 99 << ' ' << 100 << o_o;
	}
	else {
		cout << -1 << o_o;
	}
}