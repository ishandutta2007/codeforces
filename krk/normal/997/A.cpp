#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;
const ll Inf = 9000000000000000000ll;

int n, x, y;
char str[Maxn];
ll res = Inf;

int main()
{
	scanf("%d %d %d", &n, &x, &y);
	scanf("%s", str);
	x = min(x, y);
	int cnt = 0;
	for (int i = 0; i < n; )
		if (str[i] == '1') i++;
		else {
			int j = i;
			while (j < n && str[j] == '0') j++;
			cnt++;
			i = j;
		}
	for (int i = 0; i < cnt; i++)
		res = min(res, ll(x) * i + ll(y) * (cnt - i));
	res = min(res, ll(cnt) * y);
	cout << res << endl;
	return 0;
}