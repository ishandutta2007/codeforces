#include <bits/stdc++.h>
using namespace std;

const int Maxd = 7;
const int wh[Maxd] = {0, 1, 2, 0, 2, 1, 0};
const int Maxp = 3;

int a[Maxp], b[Maxp];
int res;

int main()
{
    for (int i = 0; i < Maxp; i++)
        cin >> a[i];
    int weeks = min(a[0] / 3, min(a[1] / 2, a[2] / 2));
    int add = 7 * weeks;
    a[0] -= 3 * weeks; a[1] -= 2 * weeks; a[2] -= 2 * weeks;
    for (int i = 0; i < Maxd; i++) {
        for (int j = 0; j < Maxp; j++)
            b[j] = a[j];
        int st = i, got = 0;
        while (b[wh[st]] > 0) {
            b[wh[st]]--; got++;
            st = (st + 1) % Maxd;
        }
        res = max(res, 7 * weeks + got);
    }
    cout << res << endl;
    return 0;
}