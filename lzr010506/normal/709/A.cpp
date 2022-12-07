#include <bits/stdc++.h>
using namespace std;
int N, B, D;
int main()
{
	cin >> N >> B >> D;
	int cnt = 0, ans = 0;
	while(N --)
	{
		int x;
		cin >> x;
		if(x <= B) cnt += x;
		if(cnt > D) cnt = 0, ans ++;
	}
	printf("%d", ans);
	return 0;
}