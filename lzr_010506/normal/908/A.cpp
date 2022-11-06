#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll unsigned long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

string s;

int ans = 0;

int main() 
{
    cin >> s;
    int nn = s.size();
    rep(i, 0, nn - 1)
    {
        if (s[i] >= '0' && s[i] <= '9') 
        {
            if ((s[i] - '0') % 2) ans ++;
        } 
        else 
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'  ||s[i] == 'u') ans ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}