#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
#include <cctype>
#include <ctime>

using namespace std;

int solve(int a, int b)
{
    int total = 0;
    while (a > 0 && b > 0)
    {
        if (a < b)
            swap(a, b);
        total += a / b;
        a %= b;
    }
    return total;
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << solve(a, b) << endl;
    }

    return 0;
}