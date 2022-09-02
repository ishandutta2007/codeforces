#include <iostream>
#include <vector>
#include <algorithm>
#include "assert.h"
using namespace std;
using ll = long long;
const ll INF = (ll)1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// If SECOND ever places in a pile, making that pile the largest one, they instantly lose
	// x > y > z, x banned
	//	-> FIRST plays 2x - (y+z)
	//	-> Arithmetic sequence, largest banned, add difference term
	// Thus, second can just first play some sufficiently large number

	vector<ll> vals(3);
	cin >> vals[0] >> vals[1] >> vals[2];

	cout << "First" << endl;
	cout << INF << endl;
	
	int i;
	cin >> i;
	if (i <= 0) return 0;
	--i;
	vals[i] += INF;

	ll v = (3*vals[i] - vals[0] - vals[1] - vals[2]);
	cout << v << endl;
	cin >> i;
	if (i <= 0) return 0;
	--i;
	vals[i] += v;
	
	sort(vals.begin(), vals.end());
	cout << vals[2] - vals[1] << endl;
	cin >> i;
	if (i <= 0) return 0;
	else return 1; // Should never happen
}