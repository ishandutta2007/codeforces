#include <bits/stdc++.h>
using namespace std;

const int my[] = {4, 1, 3, 2, 0, 5};

int mask;

int main()
{
    cin >> mask;
    int res = 0;
    for (int i = 0; i < 6; i++)
        res |= bool(mask & 1 << my[i]) << i;
    cout << res << endl;
    return 0;
}