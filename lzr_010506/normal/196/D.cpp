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
const int P = 29;
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 4e5 + 10;
int d, n, p[N], l[N], r[N];
char s[N], ans[N];

bool check(int i, int x)
{
    i ++;
    if(i < x) return 0;
    return ((r[i] - r[i - x] * p[x]) * p[i - x] == l[i] - l[i - x]);
}

void dfs(int i, bool flag)
{
    if(i == n) {puts(ans); exit(0);}
    if(flag) ans[i] = s[i];
    else ans[i] = 'a';
    while(ans[i] <= 'z')
    {
        l[i + 1] = l[i] + ans[i] * p[i];
        r[i + 1] = r[i] * P + ans[i];
        if(!check(i, d) && !check(i, d + 1)) dfs(i + 1, (s[i] == ans[i] && flag));
        ans[i] ++;
    }
}

int main()
{
	d = read();
	scanf("%s", s);
	n = strlen(s);
	int now = n - 1;
	while(now >= 0 && s[now] == 'z') s[now --] = 'a';
	if(now < 0) {puts("Impossible"); return 0;}
	s[now] ++;
    p[0] = 1;
	rep(i, 1, n) p[i] = p[i - 1] * P;
	//rep(i, 1, n) cout << p[i] << " ";
	dfs(0, true);
	puts("Impossible");
	return 0;
}