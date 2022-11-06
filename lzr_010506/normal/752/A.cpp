#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l, r, s;
	cin >> l >> r >> s;
	int n = r * 2;
	int ans1 = s / n;
	if(s % n) ans1 ++;
	cout << ans1 << " ";
	int ans2 = s % n;
	if(ans2 == 0) ans2 = n;
	if(ans2 % 2 == 0) cout << ans2 / 2 << " " << 'R';
	else cout << ans2 / 2 + 1 << " " << 'L';

	return 0;
}