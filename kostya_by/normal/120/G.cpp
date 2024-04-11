#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, a[111][2], b[111][2], d[111][111], c[111], pointer = 0, t, now, num = 0;
string name[111];
bool used[111];
vector<string> ans[111];

int main (int argc, const char * argv[])
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> t;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++) cin >> a[i][j] >> b[i][j];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> name[i] >> c[i];
    }
    int i = 0;
    for (; num != m; )
    {
        int ii = i, jj = 0;
        if (i >= n) 
        {
            ii -= n;
            jj = 1;
        }
        int kk = (jj + 1) % 2;
        now = t;
        while (now != 0 && num != m)
        {
            int time = max(1, c[pointer] - (a[ii][jj] + b[ii][kk]) - d[ii][pointer]);
            if (time <= now)
            {
                ans[ii].push_back(name[pointer]);
                used[pointer] = true;
                num++;
                if (num == m) break;
                while (used[pointer] == true)
                {
                    ++pointer;
                    if (pointer == m) pointer = 0;
                }
                now -= time;
                continue;
            }
            d[ii][pointer] += now;
            ++pointer;
            if (pointer == m) pointer = 0;
            while (used[pointer] == true)
            {
                ++pointer;
                if (pointer == m) pointer = 0;
            }
            now = 0;
        }
        ++i;
        if (i == 2 * n) i = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i].size();
        for (int j = 0; j < ans[i].size(); j++) cout << " " << ans[i][j];
        cout << endl;
    }
    return 0;
}