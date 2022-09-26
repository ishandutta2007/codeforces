#include<bits/stdc++.h>
using namespace std;

long long n, ans = 0;
int main()	{
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n;
	for(long long i = 0;i <= log2(n);++i)	{
		long long x = (n >> i);
		if((x << i) < n) ++x;
		x >>= 1LL;	
		ans += (x << i);
	}
	cout << ans << endl;
}