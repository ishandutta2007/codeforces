#include <bits/stdc++.h>
using namespace std;

const int Maxd = 4;

int x[Maxd];

int main()
{
    for (int i = 0; i < Maxd; i++)
        cin >> x[i];
    sort(x, x + Maxd);
    for (int i = 0; i + 1 < Maxd; i++)
        printf("%d%c", x[Maxd - 1] - x[i], i + 2 < Maxd? ' ': '\n');
    return 0;
}