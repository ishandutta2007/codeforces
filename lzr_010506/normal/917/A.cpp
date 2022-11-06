#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 10010;
char ch[N];
int n;
ll ans;
int main()
{
	scanf("%s", ch + 1);
	n = strlen(ch + 1);
	rep(i, 1, n)
	{
		int now = 0, sum = 0;
		rep(j, i, n)
		{
			if(ch[j] == ')') sum --;
			else if(ch[j]=='(') sum ++;
			else sum --, now ++;
			while(sum < 0 && now > 0) now --, sum += 2;
			if(sum < 0) break;
			if(!sum) ans ++;
		}
	}
	printf("%lld",ans);
}