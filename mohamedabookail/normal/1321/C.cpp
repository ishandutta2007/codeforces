/**
 *    author:  Mohamed Abo_Okail
 *    created: O2/O3/2O2O
**/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;
 
#define o_o "\n"
#define ll long long
 
ll _gcd(ll x, ll y) {
	return (!y ? x : _gcd(y, x % y));
}
ll _lcm(ll x, ll y) {
	return x / _gcd(x, y) * y;
}
 
int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; string s; cin >> n >> s;
	int ans = 0;
	for (char ch = 'y'; ch >= 'a'; ch--) {
		for (int i = 0; i < s.size(); i++) {
			if(ch == s[i]) {
				for (int right = i + 1; right < s.size(); right++) {
					if(s[right] == ch) continue;
					if(s[right] != ch + 1) break;
					ans++;
					s.erase(right, 1);
					right--;
				}
				for (int left = i - 1; left >= 0; left--) {
					if(s[left] == ch) continue;
					if(s[left] != ch + 1) break;
					ans++;
					s.erase(left, 1);
				}
			}
		}
	}
	cout << ans << o_o;
}