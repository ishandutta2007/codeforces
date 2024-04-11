#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+18;

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, i, sum = 0, res = 0;
	cin >> n;
	vector<ll> ar(n);
	for (i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar.begin(), ar.end());
	for (i = 0; i < n; i++)
		if (ar[i] >= sum) {
			sum += ar[i];
			res++;
		}
	cout << res;

	return 0;
}