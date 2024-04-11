#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db double
#define ls x << 1
#define rs x << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
pii ans[10010];
int cnt;
int main()
{
    int x, y, a, b;
    x = read();
    y = read();
    a = read();
    b = read();
    rep(i, a, x)
    	rep(j, b, y)
    		if(i > j)
    			ans[++ cnt] = mp(i, j);
    cout << cnt << endl;
    rep(i, 1, cnt)
    	printf("%d %d\n", ans[i].X, ans[i].Y);

    return 0;
}