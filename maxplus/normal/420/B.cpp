#include <iostream>
#include <cmath>

using namespace std;

bool out[100001];
bool lider[100001];
bool beg[100001];
bool st[100001];
int list[100001];

int main()
{
    int am = 0, n, m;
    char c;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> c;
        if (c == '+')
        {
            cin >> list[i];
            if (!beg[list[i]])
            {
                beg[list[i]] = 1;
                st[list[i]] = 1;
            }
        }
        else
        {
            cin >> list[i];
            if (!beg[list[i]])
            {
                beg[list[i]] = 1;
                st[list[i]] = 0;
                am++;
            }
            list[i] *= -1;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        if (list[i] < 0)
            am--;
        else
            am++;
        if (list[i] < 0 && ((i < m - 1 && abs(list[i + 1]) != abs(list[i])) || am > 0))
            lider[-list[i]] = 1;
        if (list[i] > 0 && ((am > 1) || (i > 0 && abs(list[i - 1]) != abs(list[i]))))
            lider[list[i]] = 1;

    }
    am = 0;
    for (int i = 1; i <= n; ++i)
        if (!lider[i])
            am++;

    cout << am << '\n';
    for (int i = 1; i <= n; ++i)
        if (!lider[i])
            cout << ' ' << i;

    return 0;
}