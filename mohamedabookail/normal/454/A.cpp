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
	int a = n / 2, b = n / 2;
	bool bol = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(j < a || j > b) {
				cout << '*';
			}
			else {
				cout << 'D';
			}
		}
		if(!a)  { bol = 0;  }
		if(bol) { a--; b++; }
		else    { a++; b--; }
		cout << o_o;
	}
}