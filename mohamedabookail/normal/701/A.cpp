/**
 *    author:  Mohamed Abo_Okail
 *    created: 24/O1/2O2O
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
	vector < int > v(n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sum /= (n / 2);
	for (int i = 0; i < n; i++) {
		if(v[i] != -1) {
			for (int j = (i + 1); j < n; j++) {
				if(v[j] != - 1 && v[i] + v[j] == sum) {
					cout << i + 1 << ' ' << j + 1 << o_o;
					v[j] = -1;
					break;
				}
			}
		}
	}
}