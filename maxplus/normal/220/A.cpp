#include <iostream>
#include <cstdlib>

using namespace std;

int n, a[100001];

void verify()
{
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
            return;
    cout << "YES";
    exit(0);
}

int main()
{
    int p, pp = -1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    verify();
    for (int i = 1; i < n; ++i)
        if (a[i] < a[i - 1])
        {
            p = i - 1;
            break;
        }
    while (p && a[p - 1] == a[p])   --p;
    swap(a[p], a[p + 1]);
    verify();
    swap(a[p], a[p + 1]);
    for (int i = p + 2; i < n; ++i)
        if (a[i] < a[i - 1] && a[i] < a[p])
        {
            pp = i;
            break;
        }
    if (pp == -1)
        for (int i = p + 2; i < n; ++i)
            if (a[i] < a[p])
            {
                pp = i;
                break;
            }
    while (pp != n - 1 && a[pp + 1] == a[pp])   ++pp;
    swap(a[p], a[pp]);
    verify();
    cout << "NO";
    return 0;
}