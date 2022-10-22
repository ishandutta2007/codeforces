#include <bits/stdc++.h>
using namespace std;

int w1, h1, w2, h2;

int main()
{
    cin >> w1 >> h1 >> w2 >> h2;
    int res = 2 * (h1 + h2 + 2) + w1 + w2 + (w1 - w2);
    cout << res << endl;
    return 0;
}