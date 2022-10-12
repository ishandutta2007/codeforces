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
	string s; getline(cin, s); char ch;
	char ar[] = { 'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y' };
	for (int i = s.size()  - 1; i >= 0; i--) {
		if(s[i] >= 'A' && s[i] <= 'Z') {
			ch = s[i]; break;
		}
		if(s[i] >= 'a' && s[i] <= 'z') {
			ch = s[i]; break;
		}
	}
	for (int i = 0; i < 12; i++) {
		if(ch == ar[i]) {
			return cout << "YES" << o_o, 0;
		}
	}
	cout << "NO" << o_o;
}