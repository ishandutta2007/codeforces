/**
 *    author:  Mohamed.Abo_Okail
 *    created: 27/12/2019
**/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define endl "\n"

int main()
{
	std::ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	} sort(a.begin(), a.end());
	int m; cin >> m;
	vector <int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	} sort(b.begin(), b.end());
	cout << a[--n] << ' ' << b[--m] << endl;
}