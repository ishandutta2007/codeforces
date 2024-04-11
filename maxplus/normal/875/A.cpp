#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()

using namespace std;

constexpr int N = 1e6;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<int> res;
    for (int i = max(0, n - 9 * 9); i <= n; ++i) {
        int s = 0;
        for (int j = i; j; j /= 10)
            s += j % 10;
        if (i + s == n)
            res.push_back(i);
    }
    cout << res.size() << '\n';
    copy(all(res), ostream_iterator<int>(cout, "\n"));
    return 0;
}