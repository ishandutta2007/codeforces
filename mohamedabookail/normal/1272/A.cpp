/**
 *    author:  Mohamed Abo_Okail
 *    created: 26/O1/2O2O
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
	int t; cin >> t;
	while(t--) {
		int ar[3];
		cin >> ar[0] >> ar[1] >> ar[2];
		sort(ar, ar + 3);
		int a = ar[1] - ar[0];
		int b = ar[2] - ar[1];
		if(!a && !b) { cout << 0 << o_o; }
		else if(!a) {
			if(ar[2] - ar[1] <= 2) { cout << 0 << o_o; }
			else {
				cout << (ar[2] - ar[1] - 2) * 2 << o_o;
			}
		}
		else if(!b) {
			if(ar[1] - ar[0] <= 2) { cout << 0 << o_o; }
			else {
				cout << (ar[1] - ar[0] - 2) * 2 << o_o;
			}
		}
		else {
			ar[0] += 1; ar[2] -= 1;
			cout << (ar[2] - ar[1] + ar[1] - ar[0]) * 2 << o_o;
		}
	}
}