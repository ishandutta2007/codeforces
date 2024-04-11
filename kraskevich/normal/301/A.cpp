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

#define F first
#define S second
#define MP make_pair
#define pii pair<int, int>

const int INF = 1000 * 1000 * 1000;

int ABS(int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vector<int> neg, pos;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        int x;
        cin >> x;

        if (x < 0)
            neg.push_back(-x);
        else
            pos.push_back(x);
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    int sum = 0;
    for (int i = 0; i < pos.size(); ++i)
        sum += pos[i];
    for (int i = 0; i < neg.size(); ++i)
        sum += neg[i];

    if (n % 2 == 1 || neg.size() % 2 == 0)
    {
        cout << sum;
        return 0;
    }

    int sum1 = sum - 2 * neg[0];
    int sum2 = -INF;
    if (pos.size())
        sum2 = sum - 2 * pos[0];

    cout << max(sum1, sum2);

    return 0;
}