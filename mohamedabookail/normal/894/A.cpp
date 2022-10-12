/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O1/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define ll long long
#define endl "\n"
 
int main() 
{
	std::ios_base::sync_with_stdio(0);
	string s; cin >> s;
	int nemo = 0;
	if(s.size() < 3) { return cout << 0, 0; } 
	for (int i = 0; i < s.size() - 2; i++) {
		if(s[i] != 'Q') { continue; }
		for (int j = (i + 1); j < s.size() - 1; j++) {
			if(s[j] != 'A') { continue; }
			for (int k = (j + 1); k < s.size(); k++) {
				if(s[k] != 'Q') { continue; }
				nemo++;
			}
		}
	}
	cout << nemo << endl;
}