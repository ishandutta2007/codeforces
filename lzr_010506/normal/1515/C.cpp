#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
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
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e5 + 10;
struct node
{
    int x, id;
}a[N];
bool operator < (const node&x, const node&y)
{
    return x.x < y.x;
}
int b[N];

signed main()
{
	int T = read();
	while(T --)
	{
        int n = read(), m = read(), x = read();
        rep(i, 1, n)
        {
            a[i].x = read();
            a[i].id = i;
        }
        sort(a + 1, a + 1 + n);
        int flag = 1, opt = 1;
        rrep(i, n, 1)
        {
            b[a[i].id] = flag;
            flag = flag + opt;
            if (flag > m)
            {
                flag = m;
                opt = -1;
            }
            else if (flag == 0)
            {
                flag = 1;
                opt = 1;
            }
        }
        printf("YES\n");
        rep(i, 1, n) printf("%d ", b[i]);
        printf("\n");
    }

}