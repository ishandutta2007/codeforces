#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
map<int, int> s;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

long long C(long long x, int y)
{
	if(y == 3) return x * (x - 1) / 2 * (x - 2) / 3;
	else return x * (x - 1) / 2;
}

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read(), s[a[i]] ++;
	map<int, int> :: iterator it;
	int cnt = 0;
	int b[4], num = 0;
	for(it = s.begin(); it != s.end(); it ++)
	{
		cnt += it -> second;
		b[++ num] = it -> second;
		if(cnt >= 3) break;
	}
	//cout << num;

	if(num == 1)
	{
		cout << C(b[1], 3);
		return 0;
	}
	if(num == 2)
	{
		if(b[1] == 1) cout << C(b[2], 2);
		else cout << b[2];
		return 0;
	}
	if(num == 3) cout << b[3];

	return 0;
}