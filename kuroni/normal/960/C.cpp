#include <bits/stdc++.h>
using namespace std;

int x, d;
vector<long long> ve;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> d;
    long long cur = 1;
    for (int i = 0; i < 30; i++)
        if (x >> i & 1)
        {
            for (int j = 0; j < i; j++)
                ve.push_back(cur);
            ve.push_back(cur += d);
            cur += d;
        }
    cout << ve.size() << '\n';
    for (long long &v : ve)
        cout << v << " ";
}