#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
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
#define INF 0x3f3f3f3f
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
int a[11];
char ch[10010];
int main()
{
	int T = read();
	while(T --)
	{
		rep(i, 0, 9) a[i] = 0;
		scanf("%s", ch + 1);
		int n = strlen(ch + 1), sum = 0;
		rep(i, 1, n) a[ch[i] - '0'] ++, sum += ch[i] - '0';
		if(sum == 0) {puts("red"); continue;}
		if(a[0] == 0) {puts("cyan"); continue;}
		a[0] --;
		int x = 0;
		//rep0(i, 10) printf("%d ", a[i]);
		rep0(i, 10) if(i % 2 == 0) x += a[i];
		//cout << "x" << x << endl;
		if(sum % 3 == 0 && x) puts("red");
		else puts("cyan");
	}
	return 0;
}