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
	int a = 0, b = 0, c = 0;
	for (int i = 1; i <= n; i++) {
		int oo; cin >> oo;
		if(i % 3 == 1) { a += oo; }
		if(i % 3 == 2) { b += oo; }
		if(i % 3 == 0) { c += oo; }
	}
	if(a > b && a > c) {
		cout << "chest" << o_o;
	}
	else if( b > a && b > c) {
		cout << "biceps" << o_o;
	}
	else {
		cout << "back" << o_o;
	}
}