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
	int a, b; cin >> a >> b;
	int nemo = 0, nemoo = 0, nemooo = 0;
	for (int i = 1; i <= 6; i++) {
		if(abs(a - i) < abs(b - i)) {
			nemo++;
		}
		else if(abs(a - i) > abs(b - i)) {
			nemooo++;
		}
		else {
			nemoo++;
		}
	}
	cout << nemo << ' ' << nemoo << ' ' << nemooo << o_o;
}