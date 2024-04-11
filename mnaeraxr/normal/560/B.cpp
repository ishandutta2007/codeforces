#include <bits/stdc++.h>

using namespace std;

bool solve(int a1, int b1, int a2, int b2, int a3, int b3){
	if (a2 > a1 || b2 > b1) return false;
	if (a3 > a1 || b3 > b1) return false;
	if (a2 + a3 <= a1) return true;
	if (b2 + b3 <= b1) return true;
	return false;
}

int main()
{
	int a1, b1, a2, b2, a3, b3;
	cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
	if (solve(a1, b1, a2, b2, a3, b3) ||
		solve(a1, b1, a2, b2, b3, a3) ||
		solve(a1, b1, b2, a2, a3, b3) ||
		solve(a1, b1, b2, a2, b3, a3))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}