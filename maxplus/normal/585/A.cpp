#include <iostream>
#include <vector>
#define N 4001

using namespace std;

int n, p[N], d[N], v[N];
vector<int> ans;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> v[i] >> d[i] >> p[i];
    for (int i = 0; i < n; ++i)
    {
        if (p[i] < 0)
            continue;
        int h = 0;
        int as = 0;
        for (int j = i + 1; j < n; ++j)
            if (p[j] >= 0)
            {
                p[j] -= max(0, v[i] - h) + as, ++h;
                if (p[j] < 0)
                    as += d[j], as = min(as, 1000001);
            }
        ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (auto i: ans)
        cout << i + 1 << ' ';
    return 0;
}