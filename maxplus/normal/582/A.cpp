#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, t;
multiset<int> table;
vector<int> found;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n * n; ++i)
        cin >> t, table.insert(t);
    while (table.size())
    {
        found.push_back(*--table.end());
        table.insert(found.back());
        for (auto i: found)
            table.erase(table.find(__gcd(i, found.back()))),
            table.erase(table.find(__gcd(i, found.back())));
    }
    for (auto i: found)
        cout << i << ' ';
    return 0;
}