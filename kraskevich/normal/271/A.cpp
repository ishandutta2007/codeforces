#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <string.h>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>

using namespace std;

bool good(int n)
{
    set<int> d;
    while (n)
    {
        d.insert(n % 10);
        n /= 10;
    }
    return d.size() == 4;
}

void solve()
{
    int y;
    cin >> y;
    ++y;
    while (!good(y))
        ++y;
    cout << y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();


    return 0;

}