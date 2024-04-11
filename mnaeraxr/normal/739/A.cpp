
#include<bits/stdc++.h>

#define endl '\n'
#define ll long long
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int d = n + 1;

	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		d = min(b - a + 1, d);
	}

	cout << d << endl;
	for (int i = 0; i < n; ++i)
		cout << i % d << " ";
	cout << endl;
}