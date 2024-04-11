/**
*    author:  Mohamed Abo_Okail
*    created: O1/11/2O2O
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
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if(!(i % a) || !(i % b) || !(i % c) || !(i % d)) ans++;
	}
	cout << ans << endl;
}