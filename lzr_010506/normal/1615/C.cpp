#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, n) for(int i = 0; i < n; i ++)
using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int cnt[2][2];
		memset(cnt, 0, sizeof(cnt));
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		rep0(i, n)
			cnt[a[i] - '0'][b[i] - '0'] ++;
		int ans = 10000000;
		if(cnt[0][1] == cnt[1][0]) ans = min(ans, cnt[0][1] * 2);
		if(cnt[1][1] == cnt[0][0] + 1) ans = min(ans, cnt[1][1] * 2 - 1);
		if(ans == 10000000) ans = -1;
		cout << ans << endl;
	}
	return 0;
}