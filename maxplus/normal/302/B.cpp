#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> s;
int m, n, t, c, lt;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> c >> t;
        s.insert({lt += c * t, i + 1});
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> t;
        cout << s.upper_bound({t, -1})->second << '\n';
    }
    return 0;
}