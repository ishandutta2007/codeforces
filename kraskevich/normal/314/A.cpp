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

long long tot, n, k, x, sum = 0, pos = 0;

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sum = 0;
    cin >> n >> k;
    tot = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        long long cur = sum - x * (tot - pos - 1) * pos;
        if (cur < k)
        {
            tot--;
            cout << i << "\n";
        }
        else
        {
            sum += x * pos;
            pos++;
        }
    }

    return 0;
}