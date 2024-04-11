#include <bits/stdc++.h>
using namespace std;
const int N = 3400;
const int P = int(1e9) + 7;

inline int add(int a, int b) { return (a + b >= P) ? (a + b - P) : (a + b);}
inline int sub(int a, int b) { return (a - b < 0) ? (a - b + P) : (a - b); }
inline void inc(int &a, int b) { a = add(a, b); }
inline int mul(int a, int b) { return (a * 1ll * b) % P; }
char s[N];
vector <int> a;
int p, ss;
int dp[N][N][2][2];
int div(const vector <int> &a, const int b, vector <int> &c)
{
    c.clear();
    long long r = 0;
    for (int i = 0; i < a.size(); i ++) 
	{
        r = r * 10ll + a[i];
        if (c.size() || r >= b) c.push_back(r / b);
        r %= b;
    }
    return r;
}

inline int calc_w(int c, int jy, int zb)
{
    if (jy) return p - calc_w(c, !jy, zb); 
    return c + 1 - zb;
}

inline int calc_W(int c, int jy, int zb)
{
    if (jy) return sub(mul(p, c + 1), calc_W(c, !jy, zb));
    if (c & 1) return sub(mul(c + 2, (c + 1) >> 1), zb * (c + 1));
    return sub(mul(c + 1, (c + 2) >> 1), zb * (c + 1));
}

int main()
{
    assert(scanf("%d %d", &p, &ss) == 2);
    assert(scanf("%s", s) == 1);
    a.resize(strlen(s));
    for (int i = 0; i < a.size(); i ++)
		a[i] = s[i] - '0';
    vector <int> b, c;
    while (a.size())
	{
        c.push_back(div(a, p, b));
        a = b;
    }
    reverse(c.begin(), c.end());
    if (ss > c.size())
	{
		puts("0");
		return 0;
	}
    dp[0][0][1][0] = 1;
    int n = c.size();
    for (int i = 0; i < n; i ++)
        for (int j = 0; j <= ss; j ++)
            for (int k = 0; k < 2; k ++)
                for (int jy = 0; jy < 2; jy ++)
				{
                    int &lzr = dp[i][j][k][jy];
                    if (lzr == 0) continue;
                    for (int csc = 0; csc < 2; csc ++)
					{
                        int nj = min(j + csc, ss);
                        if (!k)
                            inc(dp[i + 1][nj][k][csc], mul(calc_W(p - 1, jy, csc), lzr));
                        else
						{
                            if (c[i] != 0)
                                inc(dp[i + 1][nj][!k][csc], mul(calc_W(c[i] - 1, jy, csc), lzr));
                            inc(dp[i + 1][nj][k][csc], mul(calc_w(c[i], jy, csc), lzr));
                        }
                    }
                }

    int ans = 0;
    for (int k = 0; k < 2; k ++)
        inc(ans, dp[n][ss][k][0]);
    printf("%d\n", ans);
        
    return 0;
}