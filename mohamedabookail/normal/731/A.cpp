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
	string s; cin >> s;
	int nemo = 0, inx = 1;
	for (int i = 0; i < s.size(); i++) {
		int cnt = (s[i] - 96);
		if(cnt < inx) swap( cnt, inx);
		nemo += min((cnt - inx),(inx + (26 - cnt)));
		inx = (s[i] - 96);
	}
	cout << nemo << o_o;
}