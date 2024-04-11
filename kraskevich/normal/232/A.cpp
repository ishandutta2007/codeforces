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

int g[100][100];

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin >> k;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            g[i][j] = 0;
    while (k)
    {
        int mx = -1;
        int aa = 0;
        int bb = 0;
        for (int a = 0; a < 100 && mx <= 0; a++)
            for (int b = a + 1; b < 100 && mx <= 0; b++)
            {
                if (g[a][b])
                    continue;
                int cur = 0;
                for (int c = 0; c < 100; c++)
                {
                    if (c != a && c != b && g[a][c] && g[b][c])
                        cur++;
                }
                if (cur <= k && mx < cur)
                    mx = cur, aa = a, bb = b;
            }
        k -= mx;
        g[aa][bb] = g[bb][aa] = 1;
    }
    cout << 100 << endl;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            cout << g[i][j];
        cout << endl;
    }

    return 0;
}