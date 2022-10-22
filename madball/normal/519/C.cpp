#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	/*ifstream in;
	ofstream out;
	in.open("input.txt");
	out.open("output.txt");*/

	ll n, m, a, res = 0;
	cin >> n >> m;
	for (a = 0; a <= m; a++)
		res = max(res, min(n - 2 * a, (m - a) / 2) + a);
	cout << res;
	
	return 0;
}