#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T --)
	{
		map<int, int> M;
		int n, k;
		cin >> n >> k;
		vector<ll> a(n + 10);
		ll sum;
		rep(i, 1, n)
		{
			int x;
			cin >> x;
			sum += x;
			a[i] = x;
			M[x] = 1;
		}
		rep(i, 1, n)
			if(M[a[i] + k] == 1) {puts("YES"); goto L1;}

		puts("NO");
		L1:;
	}
	



	return 0;
}