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
	int nemo = 0;
	while(n--) {
		string s; cin >> s;
		int oo = 0;
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == '4' || s[i] == '7') {
				oo++;
			}
		}
		if(oo <= k) { nemo++; }
	}
	cout << nemo << o_o;
}