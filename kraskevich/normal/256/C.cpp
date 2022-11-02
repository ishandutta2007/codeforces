#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>
#include <stdlib.h>

using namespace std;


long long getLowBorder(long long value)
{
    long long low = 0, high = min(value - 1, 1000ll);
    while (low < high)
    {
        long long middle = (low + high) / 2;
        if (middle * middle * middle * middle < value)
            low = middle + 1;
        else
            high = middle;
    }
    return low;
}

long long getHighBorder(long long value)
{
    long long low = 0, high = min(value - 1, 1000 * 1000ll);
    while (low < high)
    {
        long long middle = (low + high + 1) / 2;
        if (middle * middle > value)
            high = middle - 1;
        else
            low = middle;
    }
    return low;
}


const int border[6] = {-1, 3, 15, 81, 6723, 50625};
const int nimber[6] = {0, 0, 1, 2, 0, 3};

int getNimber(long long value)
{
    if (value <= 3)
        return 0;
    if (value <= 15)
        return 1;
    if (value <= 81)
        return 2;
    if (value <= 6723)
        return 0;
    if (value <= 50625)
        return 3;
    long long low = getLowBorder(value);
    long long high = getHighBorder(value);

    set<int> seen;
    for (int i = 1; i < 6; ++i)
        if (border[i] >= low && border[i - 1] + 1 <= high)
            seen.insert(nimber[i]);
    if (high > 50625)
        seen.insert(getNimber(high));
    int result = 0;
    while (seen.count(result))
        result++;

    //cout << result << endl;

    return result;
}



int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    long long a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long result = 0;
    for (int i = 0; i < n; ++i)
        result = (result ^ getNimber(a[i]));

    cout << (result == 0 ? "Rublo" : "Furlo");

    return 0;
}