#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
int n, k, id[100100];
int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for (int i=0; i<n; ++i)
		cin >> id[i];
	for (int i = 1; k > i; ++i)
		k -= i;
	cout << id[k-1] << endl;

	return 0;
}