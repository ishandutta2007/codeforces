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
	int nemo = ((n + 1) / 2) * n;
	cout << (n % 2 ? nemo - n / 2 : nemo) << o_o;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i % 2 && j % 2) { cout << 'C'; }
			else if(!(i % 2) && !(j % 2)) { cout << 'C'; }
			else { cout << '.'; }
		}
		cout << o_o;
	}
}