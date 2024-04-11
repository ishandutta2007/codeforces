#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e+9;
ll fib[51];

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, k, i;
	cin >> n >> k;

	fib[0] = 1;
	fib[1] = 1;
	for (i = 2; i < 51; i++)
		fib[i] = fib[i - 1] + fib[i - 2];

	for (i = 0; i < n; i++)
		if (fib[n - i - 1] >= k)
			cout << i + 1 << ' ';
		else {
			i++;
			k -= fib[n - i];
			cout << i + 1 << ' ' << i << ' ';
		}

	return 0;
}