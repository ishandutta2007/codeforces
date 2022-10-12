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
	ll n, k; cin >> n >> k;
	deque < ll > dq;
	map < ll, ll > mp;
	for (int i = 0; i < n; i++) {
		ll oo; cin >> oo;
		if(mp[oo] != 1) {
			if(dq.size() == k) {
				mp[dq.back()] = 0;
				dq.pop_back();
			}
			dq.push_front(oo);
			mp[oo] = 1;
		}
	}
	cout << dq.size() << o_o;
	while(dq.size()) {
		cout << dq[0] << ' ';
		dq.pop_front();
	}
	cout << o_o;
}