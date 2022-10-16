#include <bits/stdc++.h>

using namespace std;

multiset<int> s;

int w[200000], h[200000];

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        (cin >> w[i] >> h[i]), sum += w[i], s.insert(h[i]);
    for (int i = 0; i < n; ++i)
    {
        s.erase(s.find(h[i]));
        cout << (sum - w[i]) * *prev(s.end()) << ' ';
        s.insert(h[i]);
    }
    return 0;
}