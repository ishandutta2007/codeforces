/**
 *    author:  Mohamed Abo_Okail
 *    created: O3/O2/2O2O
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
	int nemo = 0;
	for (int i = 0; i < n; i += 2) {
		if(s[i] == s[i + 1]) {
			s[i] = (s[i] == 'a' ? 'b' : 'a');
			nemo++;
		}
	}
	cout << nemo << o_o << s << endl;
}