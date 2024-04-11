#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int lh = 0, rh = n * 2 + m * 3 + 6;
    while (rh - lh > 1)
    {
        int mh = (lh + rh) / 2 - 1;
        int s = mh / 6;
        int t = mh / 3 - s;
        int d = mh / 2 - s;
        if (n + m <= s + t + d && n <= d + s && m <= t + s)
            rh = mh + 1;
        else
            lh = mh + 1;
    }
    cout << lh;
    return 0;
}