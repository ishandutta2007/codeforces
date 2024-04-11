#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 5;

int yy[N];
int T, n;

int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		vector<ll> a, b;
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++) scanf("%d", yy + i);
		a.push_back(0);
		b.push_back(0);
		for(int i = 1; i <= n; i ++)
		{
			int x;
			scanf("%d", &x);
			if(yy[i]) a.push_back(x);
			else b.push_back(x);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		reverse(a.begin() + 1, a.end());
		reverse(b.begin() + 1, b.end());
		ll ans1 = 0, ans2 = 0;
		int ta = a.size() - 1, tb = b.size() - 1;
		for(int i = 1; i <= min(tb, ta); i ++) ans1 += 2ll * a[i];
		for(int i = min(tb, ta) + 1; i <= ta; i ++) ans1 += a[i];
		for(int i = 1; i <= min(ta - 1, tb); i ++) ans1 += 2ll * b[i];
		for(int i = min(ta - 1, tb) + 1; i <= tb; i ++) ans1 += b[i];
		for(int i = 1; i <= min(tb, ta); i ++) ans2 += 2ll * b[i];
		for(int i = min(tb, ta) + 1; i <= tb; i ++) ans2 += b[i];
		for(int i = 1; i <= min(tb - 1, ta); i ++) ans2 += 2ll * a[i];
		for(int i = min(tb - 1, ta) + 1; i <= ta; i ++) ans2 += a[i];
		ll ans = max(ans1, ans2);
		printf("%lld\n", ans);
	}
	return 0;
}