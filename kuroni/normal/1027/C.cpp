#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1E4 + 5;
const double INF = 1E18 + 7;

int t, n, a, cnt[N];
vector<int> ve;

double calc(int x, int y)
{
    return 4.0 * (x + y) * (x + y) / x / y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        pair<double, pair<int, int>> ans = {INF, {0, 0}};
        cin >> n;
        int la = -1;
        while (n--)
        {
            cin >> a;
            ve.push_back(a);
            cnt[a]++;
        }
        sort(ve.begin(), ve.end());
        ve.resize(distance(ve.begin(), unique(ve.begin(), ve.end())));
        for (int &v : ve)
        {
            if (cnt[v] >= 2)
            {
                if (cnt[v] >= 4)
                    la = v;
                if (la != -1)
                    ans = min(ans, {calc(la, v), {la, v}});
                la =  v;
            }
            cnt[v] = 0;
        }
        cout << ans.second.first << " " << ans.second.second << " " << ans.second.first << " " << ans.second.second<< '\n';
        ve.clear();
    }
}