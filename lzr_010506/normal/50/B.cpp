#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a;
	long long cnt[10010];
	memset(cnt, 0, sizeof(cnt));
	cin >> a;
	int n = a.size();
	while(n --) cnt[ a[n] ] ++;
	long long ans = 0;
	for(int i = 0; i <= 10000; i ++)
		ans += cnt[i] * cnt[i];
	cout << ans;
	return 0;
}