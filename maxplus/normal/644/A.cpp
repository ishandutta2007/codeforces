#include <algorithm>
#include <iostream>
#include <vector>
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

vector<int> p[2];
int n, a, b;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i)
        p[!(i & 1)].pb(i);
    reverse(all(p[0])), reverse(all(p[1]));
    if ((a * b + 1) / 2 < (n + 1) / 2 || a * b / 2 < n / 2)
        return cout << -1, 0;
    for (int i = 0; i < a; ++i, cout << '\n')
    for (int j = 0; j < b; ++j)
        if (p[(i ^ j) & 1].size())
            cout << p[(i ^ j) & 1].back() << ' ', p[(i ^ j) & 1].pop_back();
        else
            cout << "0 ";
    return 0;
}