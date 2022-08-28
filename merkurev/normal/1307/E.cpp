#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#define open sklfjkfadhgjk
#define close djsfkljhsdjkfhkjsd

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int N = 5050;
int s[N], h[N];
int cnt[N][3];

int getVal()
{
    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 2; j >= 0; j--)
            if (cnt[i][j])
            {
                ans += j;
                break;
            }
    return ans;
}

int getCnt()
{
    int ans = 1;
    for (int i = 0; i < N; i++)
        for (int j = 2; j >= 0; j--)
            if (cnt[i][j])
            {
                ans = mul(ans, cnt[i][j]);
                break;
            }
    return ans;
}

vector <int> pos[N];

int open[N][3];
int close[N][3];

int col[N];

void addSeg(int l, int r, int ccol, int val)
{
    //eprintf("seg: [%d, %d], ccol = %d (%d %d), val = %d\n", l, r, ccol, col[l - 1], col[r], val);
    if (l == 0)
        cnt[ccol][val]++;
    else
        open[l][val]++;
    
    close[r][val]++;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        col[i] = x;
        pos[x].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &s[i], &h[i]);
        s[i]--;
    }

    for (int i = 0; i < m; i++)
    {
        //eprintf("i = %d\n", i);
        int x = s[i];
        if ((int) pos[x].size() >= h[i])
        {
            addSeg(pos[x][h[i] - 1] + 1, n, x, 1);
            addSeg(0, pos[x][(int) pos[x].size() - h[i]], x, 1);
        }
        for (int j = 0; j < m; j++)
        {
            //eprintf("j = %d\n", j);
            int y = s[j];
            if (x != y || i == j)
                continue;
            //eprintf("%d: (%d) %d + %d\n", x, (int) pos[x].size(), h[i], h[j]);
            if ((int) pos[x].size() >= h[i] + h[j])
            {
                addSeg(pos[x][h[i] - 1] + 1, pos[x][(int) pos[x].size() - h[j]], x, 2);
            }
        }
    }

    int anscnt = 0;
    int ansval = 0;

    for (int i = 0; i <= n; i++)
    {
        int pval = getVal();
        int pcnt = getCnt();
        if (i == 0)
        {
            pval = 0;
            pcnt = 0;
        }

        if (i != 0)
            for (int j = 0; j < 3; j++)
                cnt[col[i - 1]][j] += open[i][j];
        /*
        for (auto p : open[i])
        {
            //eprintf("(%d, %d)++\n", p.first, p.second);
            cnt[p.first][p.second]++;
        }
        */

        int val = getVal();
        int ccnt = getCnt();

        //eprintf("i = %d: val = %d, ccnt = %d\n", i, val, ccnt);

        if (val > ansval)
        {
            ansval = val;
            anscnt = ccnt;
        }
        else if (val == ansval)
        {
            if (pval == val)
                sadd(anscnt, sub(ccnt, pcnt));
            else
                sadd(anscnt, ccnt);
        }


        for (int j = 0; j < 3; j++)
            cnt[col[i]][j] -= close[i][j];
        /*
        for (auto p : close[i])
            cnt[p.first][p.second]--;
            */
    }

    if (ansval == 0)
        anscnt = 1;

    printf("%d %d\n", ansval, anscnt);


	return 0;
}