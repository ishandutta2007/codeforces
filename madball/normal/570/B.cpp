#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	/*freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	ll n, m;
	cin >> n >> m;
	if (n == 1)
		cout << 1;
	else
		cout << (n - m + 1 > m ? m + 1 : m - 1);
}