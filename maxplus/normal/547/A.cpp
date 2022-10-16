#include <iostream>
#include <cstring>
#define M 1000000

using namespace std;

int64_t t1[M], h1, a1, x1, y1, p1, pp1 = -1;
int64_t t2[M], h2, a2, x2, y2, p2, pp2 = -1;
int64_t m, c;

int main()
{
    cin >> m;
    cin >> h1 >> a1 >> x1 >> y1;
    cin >> h2 >> a2 >> x2 >> y2;

    c = 0;
    memset(t1, 255, sizeof(t1));
    do
        if (h1 == a1)
            pp1 = t1[h1] = c++;
        else
            t1[h1] = c++;
    while (t1[h1 = (x1 * h1 + y1) % m] == -1);
    p1 = c - t1[h1];

    c = 0;
    memset(t2, 255, sizeof(t2));
    do
        if (h2 == a2)
            pp2 = t2[h2] = c++;
        else
            t2[h2] = c++;
    while (t2[h2 = (x2 * h2 + y2) % m] == -1);
    p2 = c - t2[h2];

    if (pp2 == -1 || pp1 == -1)
    {
        cout << -1;
        return 0;
    }
    if (pp1 < t1[h1])
    {
        if (pp1 > t2[h2])
            if ((pp1 - t2[h2]) % p2 + t2[h2] != pp2)
                cout << -1;
            else
                cout << pp1;
        else
            if (pp1 != pp2)
                cout << -1;
            else
                cout << pp1;
        return 0;
    }
    if (pp2 < t2[h2])
    {
        if (pp2 > t1[h1])
            if ((pp2 - t1[h1]) % p1 + t1[h1] != pp1)
                cout << -1;
            else
                cout << pp2;
        else
            if (pp2 != pp1)
                cout << -1;
            else
                cout << pp2;
        return 0;
    }


    while (pp1 < pp2)
        pp1 += p1;
    c = 1;
    pp2 -= t2[h2];
    while (c < p2 && (pp1 - t2[h2]) % p2 != pp2)
        pp1 += p1, c++;

    if ((pp1 - t2[h2]) % p2 == pp2)
        cout << pp1;
    else
        cout << -1;
    return 0;
}