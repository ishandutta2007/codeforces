/**
 *    author:  Mohamed Abo_Okail
 *    created: 23/O1/2O2O
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
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
		if(s[i] == '1') { a++; }
	}
	b = n - a;
	if(a) { cout << 1; }
	for (int i = 0; i < b; i++) {
		cout << 0;
	}
	cout << o_o;
}