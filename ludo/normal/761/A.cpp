#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << ((a != 0 || b != 0) && abs(a - b) <= 1 ? "YES" : "NO") << endl;

	return 0;
}