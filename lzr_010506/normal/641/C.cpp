#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, Q, ji, ou;
int ans[1000010];

int turn(int x, int d)
{
    int pos = ((x + d) % n + n) % n;
    if(pos == 0) pos = n;
    return pos;
}

int main()
{
    n = read();
    Q = read();
    ji = 1, ou = 2;
    while(Q --)
    {
        int op = read();
        if(op == 2)
        {
            if(ji & 1) ji = turn(ji, 1), ou = turn(ou, -1);
            else ji = turn(ji, -1), ou = turn(ou, 1);
        }
        else
        {
            int a = read();
            ji = turn(ji, a), ou = turn(ou, a);
        }
    }
    for(int i = 1; i <= n - 1; i += 2)
    {
        ans[ji] = i;
        ji = turn(ji, 2);
    }
    for(int i = 2; i <= n; i += 2)
    {
        ans[ou] = i;
        ou = turn(ou, 2);
    }
    rep(i, 1, n) printf("%d ",ans[i]);
    return 0;
}