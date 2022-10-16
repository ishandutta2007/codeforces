#include <iostream>
#include <map>

using namespace std;

const int N = 100000;
int n, m, f[N];

map<int, int> g, h;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> f[i], --f[i];
//    for (int i = 0; i < n; ++i)
//        if (f[f[i]] != f[i])
//            return cout << "-1", 0;
    for (int i = 0; i < n; ++i)
        if (f[i] == i)
            g[i], g[i] = g.size() - 1;
    m = g.size();
    for (int i = 0; i < n; ++i)
        g[i] = g[f[i]],
        h[g[i]] = f[i];
    for (int i = 0; i < n; ++i)
        if (h[g[i]] != f[i] || i < m && g[h[i]] != i)
            return cout << "-1", 0;
    cout << m << '\n';
    for (int i = 0; i < n; ++i)
        cout << g[i] + 1 << ' ';
    cout << '\n';
    for (int i = 0; i < m; ++i)
        cout << h[i] + 1 << ' ';
    return 0;
}