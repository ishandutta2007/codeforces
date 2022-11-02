#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int n, m;
    cin >> n >> m;

    string s(m, '#'), l(m, '.'), r(m, '.');
    l[0] = r[m - 1] = '#';

    for (int row = 0; row < n; row++) {
        if (row % 2 == 0) {
            cout << s << endl;
        } else if (row % 4 == 1) {
            cout << r << endl;
        } else {
            cout << l << endl;
        }
    }

    return 0;
}