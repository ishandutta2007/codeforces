#include <bits/stdc++.h>

using namespace std;
string a[1005];
string b[1005];
int main()
{
    int n, m, k = 0;
    cin >> n >> m;
    for (int i = 0;i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int point = 0;
    for (int i = 0; i < n; i++)
    {

        if (point == m)
            break;
        while(b[point] < a[i] && point < m)
            point++;
        if (b[point] == a[i])
            k++;
    }
    n = n - k;
    m = m - k;
    if (k % 2 == 0)
    {
        n += k / 2;
        m += k / 2;
    } else
    {
        n+=k / 2 + 1;
        m+= k / 2;
    }

    if (n > m)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}