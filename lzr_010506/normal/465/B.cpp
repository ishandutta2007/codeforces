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
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2e5 + 10;
vector<int> a;
int main () 
{
    int n, x;
    n = read();
    rep(i, 1, n) 
    {
        x = read();
        if (x & 1) a.push_back(i);
    }
    int ans = a.size() ? 1 : 0;
    for (int i = 1; i < a.size(); i ++)
        ans += (a[i] != a[i - 1] + 1 ? 2 : 1);
    printf("%d\n", ans);
    return 0;
}