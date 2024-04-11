/**
*    author:  Mohamed Abo_Okail
*    created: O2/11/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define endl "\n"
#define ll long long
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
 
int main() {
	std::ios_base::sync_with_stdio(0);
	string a, b, c; cin >> a >> b >> c;
	a += b;
	sort(all(a));
	sort(all(c));
	cout << (a == c ? "YES" : "NO") << endl;
}