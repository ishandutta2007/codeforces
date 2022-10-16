#include <iostream>
#include <map>

using namespace std;

int n, a;
map<int, int> m;

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a, ++m[1 << (__builtin_ctz(a))];
    cout << m.rbegin()->first << ' ' << m.rbegin()->second;
    return 0;
}