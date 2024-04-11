#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>

const int MAX_N = 120000;

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

int a[MAX_N];

int f[3][MAX_N];

int w[3];
int go[MAX_N];
vector<pair<int, int> > ans;



int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    //reverse(a, a + n);

    int at = a[n - 1];
    if (n == 1)
    {
        cout << 1 << "\n";
        cout << 1 << " " << 1;
        return 0;
    }

    f[1][0] = 0;
    f[2][0] = 0;
    for (int i = 0; i < n; ++i)
    {
        f[2][i + 1] = f[2][i];
        f[1][i + 1] = f[1][i];
        ++f[a[i]][i + 1];
    }


    for (int i = 0; i < n; ++i)
        go[i] = 0;

    for (int i = 1; i < n; ++i)
    {
        go[0] = i - 1;
        if (f[1][i] == f[2][i])
            continue;
        int t = max(f[2][i], f[1][i]);
        if (f[a[i - 1]][i] < f[3 - a[i - 1]][i])
            continue;
        w[1] = 0;
        w[2] = 0;
        ++w[a[i - 1]];
        for (int j = 1; ; ++j)
        {
            go[j] = max(go[j], go[j - 1] + 1);
            while (go[j] < n && (go[j] <= go[j - 1] || (f[1][go[j] + 1] - f[1][go[j - 1] + 1] < t && f[2][go[j] + 1] - f[2][go[j - 1] + 1] < t)  ))
                ++go[j];
            if (go[j] == n)
                break;
            if (f[1][go[j] + 1] - f[1][go[j - 1] + 1] == t)
                ++w[1];
            else
                ++w[2];
            if (go[j] == n - 1)
            {
                if (w[at] > w[3 - at])
                {
                    ans.push_back({w[at], t});
                }
                break;
            }
        }
    }

    if (f[at][n] > f[3 - at][n])
    {
        ans.push_back({1, f[at][n]});
    }


    sort(ans.begin(), ans.end());

    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i)
    {
        printf("%d %d\n", ans[i].first, ans[i].second);

    }
    return 0;
}