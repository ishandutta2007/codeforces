#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int k;
	cin >> k;
	const int B = (1 << 17);
	const int A = (1 << 18) - 1;
	cout << 3 << ' ' << 3 << '\n';
	cout << A << ' ' << A << ' ' << B << ' ';
	cout << A << ' ' << k << ' ' << A << ' ';
	cout << B << ' ' << A << ' ' << k << ' ';
	cout << '\n';
}