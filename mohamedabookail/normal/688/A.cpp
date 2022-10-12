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
	int n, d; cin >> n >> d;
	int nemo = -1, cnt = 0;
	for (int i = 0; i < d; i++) {
		string s; cin >> s;
		bool bol = 0;
		for (int j = 0; j < n; j++) {
			if(s[j] == '0') { bol = 1; }
		}
		if(bol) { cnt++; }
		else { cnt = 0; }
		nemo = max(nemo, cnt);
	}
	cout << nemo << o_o;
}