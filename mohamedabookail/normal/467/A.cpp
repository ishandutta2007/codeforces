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
	int n; cin >> n;
	int nemo = 0;
	while(n--) {
		int a, b; cin >> a >> b;
		if(a < b - 1) { nemo++; }
	}
	cout << nemo << o_o;
}