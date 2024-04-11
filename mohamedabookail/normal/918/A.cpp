/**
 *    author:  Mohamed Abo_Okail
 *    created: 22/O1/2O2O
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
	int n; cin >> n;
	map < int, bool > mp;
	mp[1] = true, mp[2] = true;
	int a = 1, b = 2, c = 0;
	while(b <= 1000) {
		c = b;
		b += a;
		a = c;
		mp[b] = true;
	}
	for (int i = 1; i <= n; i++) {
		if(mp[i]) {
			cout << 'O';
		}
		else {
			cout << 'o';
		}
	}
}