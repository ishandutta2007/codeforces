#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1000000007;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll k, i, j, j2;
	cin >> k;
	vector<ll> cnt(k);
	for (i = 0; i < k; i++)
		cin >> cnt[i];

	vector<ll> addxcnt;
	ll res = 1, total = 0;
	for (i = 0; i < k; i++) {
		addxcnt = vector<ll>(total + 1, 0);
		addxcnt[total] = res;
		for (j = 0; j < cnt[i]; j++) {
			total++;
			res = 0;
			for (j2 = addxcnt.size() - 1; j2 >= 0; j2--) {
				addxcnt[j2] = (addxcnt[j2] + res) % inf;
				res = addxcnt[j2];
			}
		}
	}

	cout << res;

	return 0;
}