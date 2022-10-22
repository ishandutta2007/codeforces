#include <iostream>
using namespace std;

int n, m, k;

int main()
{
    int x, y;
    cin >> n >> m >> k;
    bool win = false;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        win = win || x <= 5 || x >= n-4 || y <= 5 || y >= m-4;
    }
    if (win) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}