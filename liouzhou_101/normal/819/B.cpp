#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

const int MAXN = 2000010;

int n;
int a[MAXN];

int main()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++ i)
	{
		scanf("%d", &a[i]);
		a[i+n] = a[i];
	}
	ll cur = 0;
	priority_queue<int, vector<int>, greater<int> > Q;
	ll cnt = 0;
	for (int i = 1; i <= n; ++ i)
	{
		if (a[i] < i)
		{
			cur += i-a[i];
			cnt ++;
			Q.push(i-a[i]);
		}
		else
		{
			cur += a[i]-i;
		}
	}
	ll ans = cur, pos = n;
	for (int i = n+1; i < n+n; ++ i)
	{
		cur = cur-cnt+(n-cnt);
		cur -= a[i-n];
		while (!Q.empty() && Q.top() == i-n)
		{
			-- cnt;
			Q.pop();
		}
		if (a[i] < n)
		{
			cur += n-a[i];
			cnt ++;
			Q.push(i-a[i]);
		}
		else
		{
			cur += a[i]-n;
		}
		if (cur < ans)
		{
			ans = cur;
			pos = i;
		}
	}
	if (pos == n)
		pos = 0;
	else
		pos = n-(pos-n);
	cout << ans << " " << pos << endl;
	
	return 0;
}