#include <bits/stdc++.h>
using namespace std;
int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
	int month, day;
	cin >> month >> day;
	int ans = 1;
	a[month] -= 7 - day + 1;
	//cout << a[month] << " ";
    ans += ceil((double)a[month] / 7.0);
    cout << ans;
    return 0;
}