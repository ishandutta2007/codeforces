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
	int n; string s; cin >> n >> s;
	int nemo = 0, cnt = 0; s += '0';
	for (int i = 0; i < n; i++) {
		if(s[i] != s[i + 1]) {
			nemo += cnt;
			cnt = -1;
		}
		cnt++;
	}
	cout << nemo << o_o;
}