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

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const int N = 100 * 1000 + 100;
int dp[N];
int a[N];
int pos[N];
vector<int> g[N];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r" stdin);
    //freopen("output.txt", "w", stdout);

    fill(pos, pos + N, -1);
    fill(dp, dp + N, 1);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    for (int f = 2; f < N; f++)
    {
        int pp = pos[f];
        for (int x = 2 * f; x < N; x += f)
        {
            int p = pos[x];
            if (p == -1)
                continue;
            if (pp >= 0)
                g[p].push_back(pp);
            pp = p;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++)
            dp[i] = max(dp[i], dp[g[i][j]] + 1);

    cout << *max_element(dp, dp + N);

    return 0;
}