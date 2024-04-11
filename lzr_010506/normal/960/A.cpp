#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi totor<int>
#define vl totor<ll>
#define rep(i, x, y) for(register int i = x; i <= y; i ++)
#define rrep(i, x, y) for(register int i = x; i >= y; i --)
#define eps 1e-15
#define lb(x) x & -x
#define sz(x) (x).size()
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
char ch[100010];
int main()
{
	scanf("%s", ch + 1);
	int len = strlen(ch + 1);
	int a = 0, b = 0, c = 0;
	int i = 1;
	for(; i <= len; i ++)
		if (ch[i] == 'a') a ++; 
		else break;
	for(; i <= len; i ++)
		if (ch[i] == 'b') b ++; 
		else break;
	for(; i <= len; i ++)
		if (ch[i] == 'c') c ++; 
		else break;
	if (a + b + c != len){ puts("NO"); return 0; }
	if (!a || !b){ puts("NO"); return 0; }
	if (c == a || c == b){ puts("YES"); return 0; }
	puts("NO");
	return 0;
}