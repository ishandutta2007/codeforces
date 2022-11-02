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

const int N = 100 * 1000 + 10;
int a[N], n, res = 0;
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
    {
        while (!s.empty() && s.top() < a[i])
            s.pop();
        if (!s.empty())
            res = max(res, a[i] ^ s.top());
        s.push(a[i]);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!s.empty() && s.top() < a[i])
            s.pop();
        if (!s.empty())
            res = max(res, a[i] ^ s.top());
        s.push(a[i]);
    }

    cout << res;

    return 0;
}