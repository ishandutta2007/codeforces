#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, p;
	cin >> n >> p;
	for(int i = 0; i <= 40; i++)
	{
		int e = n - i * p;
		if(e < i)
		{
			break;
		}
		int cnt = 0;
		while(e > 0)
		{
			cnt += e % 2;
			e = e / 2;
		}
		if(cnt <= i)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}