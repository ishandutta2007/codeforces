#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;
 
template <typename T>
 
void read(T &a)
{
	T x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	a = x * f;
}
 
template <typename T,typename... Args> void read(T &t,Args &... args) {read(t); read(args...); }

int gcd(int x,int y)
{
	if (!y) return x;
	else return gcd(y,x % y);
}
int n,a[N],b[N],tmp = 0,cnt = 0;
std::map<pair<int,int>,int> mp;
 
signed main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i]);
	for (int i = 1; i <= n; i++)
	{
		read(b[i]);
		if (a[i] && b[i])
		{
			int tmppp = gcd(abs(a[i]),abs(b[i]));
			int tmpp = a[i] / abs(a[i]);
			tmpp *= b[i] / abs(b[i]);
			mp[make_pair(-tmpp * abs(b[i]) / tmppp,abs(a[i]) / tmppp)]++;
		}
		if (!b[i] && a[i]) tmp++;
		if (!b[i] && !a[i]) cnt++;
	}
	int ans = tmp + cnt;
	for (map<pair<int,int>,int>::iterator it = mp.begin(); it != mp.end(); it++)
	{
		if (it -> second + cnt > ans) ans = it -> second + cnt;
	}
	printf("%lld\n",ans);
	return 0;
}