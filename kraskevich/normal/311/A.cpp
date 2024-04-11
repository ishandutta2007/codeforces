#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long n, k;
    cin >> n >> k;

    long long mx = n * (n - 1) / 2;
    if (mx <= k)
    {
        cout << "no solution";
        return 0;
    }

    int y = 0;
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        cout << x << " " << y << endl;
        x++;
        y += 10000;
    }

    return 0;
}