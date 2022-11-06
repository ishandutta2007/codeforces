#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const ll mod = 100000003;
const int N = 1e6 + 10;
int n, m;
ll hasha[N], va[N], hashb[N];
vector<int> E;

int main()
{
	n = read();
	m = read();
	va[1] = 1;
	rep(i, 2, n)
        va[i] = va[i - 1] * mod;
	rep(i, 1, m)
	{
		int u, v;
		u = read();
		v = read();
		hasha[u] += va[v];
        hasha[v] += va[u];
	}
	rep(i, 1, n) hashb[i] = hasha[i] + va[i];
    ll ans = 0;
    sort(hasha + 1, hasha + 1 + n);
    sort(hashb + 1, hashb + 1 + n);
    ll now = hasha[1], cnt = 1;
   	rep(i, 2, n)
    {
        if(now == hasha[i]) cnt ++;
        else
        {
            ans += (cnt * (cnt - 1)) / 2;
            now = hasha[i];
            cnt = 1;
        }
    }
    ans += (cnt * (cnt - 1)) / 2;
    now = hashb[1];
    cnt = 1;
    rep(i, 2, n)
    {
        if(now == hashb[i]) cnt ++;
        else
        {
            ans += (cnt * (cnt - 1)) / 2;
            now = hashb[i];
            cnt = 1;
        }
    }
    ans += (cnt * (cnt - 1)) / 2;
    printf("%I64d\n",ans);
	return 0;
}