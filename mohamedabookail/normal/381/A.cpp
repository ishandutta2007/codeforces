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
	deque < int > dq(n);
	int a = 0, b = 0, f = 1;
	for (int i = 0; i < n; i++) {
		cin >> dq[i];
	}
	while(dq.size()) {
		int cnt = 0;
		if(dq.front() > dq.back()) {
			cnt = dq.front();
			dq.pop_front();
		}
		else {
			cnt = dq.back();
			dq.pop_back();
		}
		if(f) {
			a += cnt;
			f = 0;
		}
		else {
			b += cnt;
			f = 1;
		}
	}
	cout << a << ' ' << b << o_o;
}