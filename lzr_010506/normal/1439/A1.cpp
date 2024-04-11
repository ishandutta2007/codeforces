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
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
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
const int N = 1010;
int n, m;
char f[N][N];

struct Node 
{
    int a, b, c, d, e, f;
};
vector<Node> ans;

int main() 
{
	int T = read();
	while(T --)
	{
        n = read(); 
        m = read(); 
        rep(i, 1, n) scanf("%s", f[i] + 1);
        ans.clear();
	
		if (n % 2 == 1) 
        {
        	rep(i, 1, m)
                if (f[n][i] == '1') 
				{
                    if (i == 1)
                    {
                        f[n - 1][1] ^= 1;
                        f[n - 1][2] ^= 1;
                        ans.pb((Node){n, 1, n - 1, 1, n - 1, 2});
                    } 
                    else 
                    {
                        f[n - 1][i] ^= 1;
                        f[n - 1][i - 1] ^= 1;
                        ans.pb((Node){n, i, n - 1, i, n - 1, i - 1});
                    }
                }
            n --;
        }
		
        if (m % 2 == 1) 
        {
        	rep(i, 1, n)
                if (f[i][m] == '1') 
                {
                    if (i == 1)
                    {
                        f[1][m - 1] ^= 1;
                        f[2][m - 1] ^= 1;
                        ans.pb({1, m, 1, m - 1, 2, m - 1});
                    } 
                    else 
                    {
                        f[i][m - 1] ^= 1;
                        f[i - 1][m - 1] ^= 1;
                        ans.pb({i, m, i, m - 1, i - 1, m - 1});
                    }
                }
            m --;
        }

        
        
        rep(i, 1, n / 2)
        	rep(j, 1, m / 2)
        	{
                bool a = 0, b = 0, c = 0, d = 0;
                if (f[i * 2 - 1][j * 2 - 1] == '1') b ^= 1, c ^= 1, d ^= 1;
                if (f[i * 2 - 1][j * 2] == '1') a ^= 1, c ^= 1, d ^= 1;
                if (f[i * 2][j * 2 - 1] == '1') a ^= 1, b ^= 1, d ^= 1;
                if (f[i * 2][j * 2] == '1') a ^= 1, b ^= 1, c ^= 1;
                if (a) ans.pb((Node) {i * 2 - 1, j * 2, i * 2, j * 2 - 1, i * 2, j * 2}); 
                if (b) ans.pb((Node) {i * 2 - 1, j * 2 - 1, i * 2, j * 2 - 1, i * 2, j * 2}); 
                if (c) ans.pb((Node) {i * 2 - 1, j * 2 - 1, i * 2 - 1, j * 2, i * 2, j * 2});
                if (d) ans.pb((Node) {i * 2 - 1, j * 2 - 1, i * 2 - 1, j * 2, i * 2, j * 2 - 1}); 
            }
        printf("%d\n", sz(ans));
        for (auto i : ans) printf("%d %d %d %d %d %d\n", i.a, i.b, i.c, i.d, i.e, i.f);
    }
    return 0;
}