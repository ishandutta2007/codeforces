#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

const int N = 100;
const int M = 14 / 2;
const int MASK = (1 << M) - 1;

int main() {
	cout << "?";
	for (int i = 1; i <= N; ++i) cout << ' ' << i; cout << endl;
	int v1;
	cin >> v1;

	cout << "?";
	for (int i = 1; i <= N; ++i) cout << ' ' << (i << M); cout << endl;
	int v2;
	cin >> v2;

	cout << "! " << ((v1 & (MASK << M)) | (v2 & MASK)) << endl;
}