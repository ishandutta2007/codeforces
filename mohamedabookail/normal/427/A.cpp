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
	int nemo = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		int oo; cin >> oo;
		if(oo > 0) { cnt += oo; }
		else {
			if(cnt >= abs(oo)) { cnt += oo; }
			else {
				nemo += abs(oo);
			}
		}
	}
	cout << nemo << o_o;
}