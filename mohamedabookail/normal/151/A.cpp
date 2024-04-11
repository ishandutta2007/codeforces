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
	ll n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	ll flag1 = k * l / nl;
	ll flag2 = c * d;
	ll flag3 = p / np;
	cout << min({flag1, flag2, flag3}) / n << endl;
}