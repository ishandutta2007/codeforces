#include <iostream>

using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    int m[n], r[n];
    for (int i = 0; i < n; ++i)
        cin >> m[i];
    for (int i = 0; i < n; ++i)
        cin >> r[i];
    for (int i = 0; i < 720720; ++i)
    for (int j = 0; j < n; ++j)
    if (i % m[j] == r[j])
        {ans++;break;}
    cout.precision(10);
    cout << fixed << ans / 720720.;
    return 0;
}