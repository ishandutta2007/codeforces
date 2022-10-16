#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int64_t n, x, y, a;
vector<int> v;

int main()
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n >> x >> y;
    for (int i = 0; i < n; ++i)
        cin >> a, v.push_back(a);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i)
    {
        x -= v[i] >> 1, y -= v[i] & 1;
        if (2 * x + y < 0 || x + y < 0)
            return cout << i, 0;
    }
    cout << n;
    return 0;
}