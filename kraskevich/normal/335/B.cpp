#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>

using namespace std;

#define PII pair<int, int>
#define PLL pair<long long, long long>
#define PIL pair<int, long long>
#define PLI pair<long long, int>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __dv__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__
#define y0 y100500_0
#define y1 y100500_1
#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<vector<int> > VII;
typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 50 * 1000 + 10;
const int L = 111;

string s;
int n;
vector<int> at[26];
int f[N][26];
PII go[N][L];
char cc[N][L];
int dp[N][L];
string ll, rr;

void rec(int i, int j)
{
    if (i == 0 || j == 0)
        return;
    int l = go[i][j].S;
    if (l == j)
        rec(i - 1, l);
    if (l == j - 1)
    {
        ll += cc[i][j];
        rec(i - 1, l);
    }
    if (l == j - 2)
    {
        ll += cc[i][j];
        rr += cc[i][j];
        rec(i - 1, l);
    }
}

void print()
{
    reverse(ll.begin(), ll.end());
    cout << ll << rr;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> s;
    s = '$' + s;
    n = s.length();
    for (int i = 1; i < n; i++)
        at[s[i] - 'a'].PB(i);
    for (int i = 1; i <= n; i++)
        for (int c = 0; c < 26; c++)
        {
            int p = lower_bound(at[c].begin(), at[c].end(), i) - at[c].begin();
            if (p == 0)
                f[i][c] = -1;
            else
                f[i][c] = at[c][p - 1];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < L; j++)
            dp[i][j] = -1;
    dp[0][0] = n;
    for (int i = 1; i < n; i++)
    {
        for (int len = 0; len <= 100; len++)
        {
            dp[i][len] = dp[i - 1][len];
            go[i][len] = PII(i - 1, len);
            cc[i][len] = 0;
        }
        for (int len = 0; len <= 100; len++)
        {
            int r = dp[i - 1][len];
            if (r <= i)
                continue;
            if (f[r][s[i] - 'a'] == -1)
                continue;
            r = f[r][s[i] - 'a'];
            if (r < i)
                continue;
            if (r == i)
            {
                if (dp[i][len + 1] < r)
                {
                    dp[i][len + 1] = r;
                    go[i][len + 1] = PII(i - 1, len);
                    cc[i][len + 1] = s[i];
                }
            }
            else
            {
                if (dp[i][len + 2] < r)
                {
                    dp[i][len + 2] = r;
                    go[i][len + 2] = PII(i - 1, len);
                    cc[i][len + 2] = s[i];
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
        if (dp[i][100] >= i)
        {
            rec(i, 100);
            print();
            return 0;
        }
    int mx = 0;
    for (int i = 1; i < n; i++)
        for (int l = 0; l <= 100; l++)
            if (dp[i][l] >= i)
                mx = max(mx, l);
    for (int i = 1; i < n; i++)
        if (dp[i][mx] >= i)
        {
            rec(i, mx);
            print();
            return 0;
        }

    return 0;
}