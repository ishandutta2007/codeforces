#include <iostream>
#include <cstdio>
using namespace std;

int pre = -1, c;
long long ans = 1;

int main()
{
    cin >> c;
    for (int i = 1; cin >> c; i++)
        if (c)
        {
            if (pre != -1)
                ans *= (i - pre);
            pre = i;
        }
    cout << (pre == -1 ? 0 : ans);
}