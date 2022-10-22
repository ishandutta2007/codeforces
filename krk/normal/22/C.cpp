#include <iostream>
using namespace std;

int n, m, v;

int main()
{
    cin >> n >> m >> v;
    if (m < n - 1 || (n - 1) * (n - 2) / 2 + 1 < m) cout << "-1\n";
    else {
         int pr = 1; if (pr == v) pr++;
         for (int i = 1; i <= n && m; i++) if (i != v) {
             cout << v << " " << i << endl; m--;
         }
         for (int i = 1; i <= n && m; i++) if (i != v && i != pr)
            for (int j = i + 1; j <= n && m; j++) if (j != v && j != pr) {
                cout << i << " " << j << endl; m--;
            }
    }
    return 0;
}