#include <iostream>
#define N 101

using namespace std;

int n, k, *b, *s, a[N], c[N];

int main()
{
    cin >> n >> k;
    b = s = a;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        if (a[i] > *b)
            b = a + i;
        if (a[i] < *s)
            s = a + i;
    }
    if (*b - *s > k)
    {
        cout << "NO";
        return 0;
    }
    else
        cout << "YES\n";
    for (int i = *s; i < *b; ++i)
        c[i] = i - *s;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < a[i]; ++j)
            cout << c[j] + 1 << ' ';
        cout << '\n';
    }
    return 0;
}