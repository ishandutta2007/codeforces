#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{

    int n, group[5] = {0}, result = 0;
    cin >> n;
    while (n--)
    {
        int c;
        cin >> c;
        group[c]++;
    }
    result += group[4];
    group[4] = 0;
    result += group[3];
    group[1] -= min(group[3], group[1]);
    group[3] = 0;
    result += (group[2] / 2);
    group[2] %= 2;
    result += group[2];
    group[1] -= min(2 * group[2], group[1]);
    group[2] = 0;
    result += (group[1] + 3) / 4;
    cout << result << '\n';
}