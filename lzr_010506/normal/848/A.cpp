#include <bits/stdc++.h>
#define db double
#define ll long long
#define X first
#define Y second
#define pii pair<int, int>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define REP(i, y) rep(i, 0, y - 1)
#define pb push_back
#define mp make_pair
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
string s;
int k;
int main()
{
    int k = read();
    if(k == 0) {puts("a"); return 0;}
    rep(i, 0, 25)
    {
		int tot = 0, now = 1;
		if(k) s.pb('a' + i);
		while(k >= now)
		{
			s.pb('a' + i);
			k -= now ++;
		}
	}
	cout << s;
    return 0;
}