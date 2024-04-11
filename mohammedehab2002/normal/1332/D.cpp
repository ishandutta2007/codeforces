#include <bits/stdc++.h>
using namespace std;
#define pw (1<<18)-1
int main()
{
	int k;
	cin >> k;
	cout << 3 << ' ' << 3 << endl << pw << ' ' << k << ' ' << 0 << endl << (pw^k) << ' ' << pw << ' ' << k << endl << 0 << ' ' << k << ' ' << k;
}