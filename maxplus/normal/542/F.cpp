#include <iostream>
#include <cstring>
#define N 1001

using namespace std;

int n, T, u[N], in[N], t[N];

int ans(int d)
{
    int a1 = 0;
    for (int i = 0; i < n; ++i)
        if (!u[i] && t[i] + d <= T)
            a1 = max(a1, in[i]);
    if (a1 == 0)
        return a1;
    int u1[N];
    memmove(u1, u, sizeof(u1));
    int a2 = ans(d + 1) + ans(d + 1);
    if (a2 >= a1)
        return a2;
    else
    {
        memmove(u, u1, sizeof(u1));
        for (int i = 0; i < n; ++i)
            if (!u[i] && t[i] + d <= T && in[i] == a1)
            {
                u[i] = 1;
                break;
            }
        return a1;
    }
}

int main()
{
    cin >> n >> T;
    for (int i = 0; i < n; ++i)
        cin >> t[i] >> in[i];
    cout << ans(0);
    return 0;
}