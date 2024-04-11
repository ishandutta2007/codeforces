/**
*    author:  Mohamed Abo_Okail
*    created: O9/11/2O2O
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
	//freopen("text.in", "r", stdin);
	string a, b; cin >> a >> b;
	for(int i = 0; i < sz(a); i++) a[i] = tolower(a[i]);
	for(int i = 0; i < sz(b); i++) b[i] = tolower(b[i]);
	cout << (a == b ? 0 : a > b ? 1 : -1) << endl;
}