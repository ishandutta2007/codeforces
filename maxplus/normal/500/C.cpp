#include <algorithm>
#include <iostream>
#include <vector>
#define N 1002

using namespace std;

int n, m, w[N], u[N], b[N], ans;
vector<int> v;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 0; i < m; ++i)
    {
        cin >> b[i];
        if (u[b[i]])
            continue;
        u[b[i]] = 1;
        v.push_back(b[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < v.size(); ++j)
        {
            if (v[j] == b[i])
            {
                reverse(v.begin(), v.begin() + j), reverse(v.begin(), v.begin() + j + 1);
                break;
            }
            ans += w[v[j]];
        }
    }
    cout << ans;
    return 0;
}