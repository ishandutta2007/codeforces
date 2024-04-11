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
	bool bol = 0;
	while(n--) {
		string s; int a, b;
		cin >> s >> a >> b;
		if(a >= 2400 && b > a) {
			bol = 1;
		}
	}
	cout << (bol ? "YES" : "NO") << o_o;
}