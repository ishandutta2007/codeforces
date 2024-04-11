/**
 *    author:  Mohamed Abo_Okail
 *    created: 24/O1/2O2O
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
	int nemo = 240 - k, nemoo = 0;
	for (int i = 1; i <= n; i++) {
		nemo -= (i * 5);
		if(nemo >= 0) { nemoo++; }
	}
	cout << nemoo << o_o;
}