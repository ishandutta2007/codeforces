#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
	int n;
	cin >> n;
	cout << n / 2 << endl;
	for (int i = 0; i < n / 2 - n % 2; i++)
		cout << 2 << " ";
	if (n % 2)
		cout << 3;
	cout << endl;
}