#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[200];
struct Node
{
	char ch;
	int x;
}a[10];
int main()
{
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; i ++)
		cnt[ s[i] ] ++;
	a[1].ch = 'B', a[1].x = 1;
	a[2].ch = 'u', a[2].x = 2;
	a[3].ch = 'l', a[3].x = 1;
	a[4].ch = 'b', a[4].x = 1;
	a[5].ch = 'a', a[5].x = 2;
	a[6].ch = 's', a[6].x = 1;
	a[7].ch = 'r', a[7].x = 1;
	int ans = 0x7f7f7f7f;
	for(int i = 1; i <= 7; i ++)
		ans = min(ans, cnt[ a[i].ch ] / a[i].x);
	cout << ans;
	return 0;
}