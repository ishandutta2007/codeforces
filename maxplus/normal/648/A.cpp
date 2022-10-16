#include <iostream>

using namespace std;

int n, m, ans1, ans2;
char a[101][101];
int b[101];

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
        cin >> a[i][j];
    for (int j = 0; j < m; ++j)
    for (b[j] = 0; a[b[j]][j] == '.'; ++b[j]);
    for (int j = 1; j < m; ++j)
        ans1 = max(ans1, b[j] - b[j - 1]),
        ans2 = max(ans2, -b[j] + b[j - 1]);
    cout << ans2 << ' ' << ans1;
    return 0;
}