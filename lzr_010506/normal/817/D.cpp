#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
const int INF = 1e9 + 10;
int n;
int a[N], prel[N], prer[N];

stack<int> st;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	st.push(0);
	a[0] = -INF, a[n + 1] = -INF;
	for (int i = 1; i <= n + 1; i ++)
	{
		while (a[i] < a[st.top()])
		{
			prer[st.top()] = i - 1;
			st.pop();
		}
		prel[i] = st.top() + 1;
		st.push(i);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i ++)
		ans -= a[i] * 1LL * (i - prel[i] + 1) * (prer[i] - i + 1);

	while (!st.empty()) st.pop();
	st.push(0);
	a[0] = INF, a[n + 1] = INF;
	for (int i = 1; i <= n + 1; i ++)
	{
		while (a[i] > a[st.top()])
		{
			prer[st.top()] = i - 1;
			st.pop();
		}
		prel[i] = st.top() + 1;
		st.push(i);
	}
	for (int i = 1; i <= n; i ++)
		ans += a[i] * 1LL * (i - prel[i] + 1) * (prer[i] - i + 1);
	cout << ans << endl;
	return 0;
}