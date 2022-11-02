#include <algorithm>
#include <iostream>
#include <string.h>
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

using namespace std;

int dp[111][111][111];
int cur[111];
int len[111];
string A, B;
string T;
int a, b;

int work(string S)
{
    int n = T.length();
    int m = S.length();
    int pa = 0;
    fill(cur, cur + 111, 111);
    for (int i = 0; i < n && pa < m; i++)
    {
        if (pa < m && T[i] == S[pa])
            pa++;
        cur[pa] = min(cur[pa], i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> a >> b;
    cin >> A >> B;
    int n = A.length();
    int m = B.length();
    for (int i = 0; i < 111; i++)
        for (int j = 0; j < 111; j++)
            for (int k = 0; k < 111; k++)
                dp[i][j][k] = 111;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            string S = B.substr(j, m - j);
            T = A.substr(i, n - i);
            work(S);
            for (int k = 0; k < 111; k++)
                dp[i][j][k] = min(dp[i][j][k], cur[k] + i);
        }
    /*for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int l = 0; l <= m; l++)
                cout << i << " " << j << " " << l << " " << dp[i][j][l] << endl;*/
    for (int i = 0; i < m; i++)
    {
        int pa = 0;
        int pb = i;
        len[i] = 0;
        for (;;)
        {
            int cur = 0;
            while (cur + 1 <= m && dp[pa][pb][cur + 1] < n)
                cur++;
            if (cur == 0)
                break;
            len[i] += cur;
            pa = dp[pa][pb][cur] + 1;
            if (pa >= n)
                break;
            pb += cur;
            pb %= m;
        }
    }
    /*for (int i = 0; i < 10; i++)
        cout << len[i] << " ";*/
    int L = 0;
    int pb = 0;
    for (int i = 0; i < a; i++)
    {
        L += len[pb];
        pb += len[pb];
        pb %= m;
    }
    //cerr << L << endl;
    L /= m;
    L /= b;
    cout << L;

    return 0;
}