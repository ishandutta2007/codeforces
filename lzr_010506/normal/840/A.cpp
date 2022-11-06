#include <bits/stdc++.h>
#include <math.h>
#define uint unsigned long long
#define ll long long
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
#define ept 1e-9

using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
struct Node
{
	int x, y;
}b[N];
int ans[N], a[N];
bool cmp1(Node a, Node b)
{
	if(a.x == b.x) return a.y > b.y;
	return a.x < b.x;
}
int main()
{
	int n = read();
	rep(i, 1, n) a[i] = read();
    rep(i, 1, n) b[i].x = read(), b[i].y = i;
    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    sort(b + 1, b + n + 1, cmp1);
    rep(i, 1, n)
    	ans[b[i].y] = a[i];
    rep(i, 1, n)
     	cout << ans[i] << " ";
    return 0;
}