#include <bits/stdc++.h>

using namespace std;

int main()
{
	int na, nb;
	cin >> na >> nb;
	int k, m;
	cin >> k >> m;

	vector<int> a(na);
	vector<int> b(nb);

	for (int i = 0; i < na; ++i)
		cin >> a[i];
	for (int i = 0; i < nb; ++i)
		cin >> b[i];

	cout << (a[k - 1] < b[nb - m] ? "YES" : "NO") << endl;		
}