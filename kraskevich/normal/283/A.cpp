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

const int N = 300 * 1000;
long long add[N];
long long val[N];
long long sum = 0;
int size = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fill(add, add + N, 0);
    fill(val, val + N, 0);

    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int a, x;
            cin >> a >> x;
            add[a - 1] += x;
            sum += a * x;
        }
        if (t == 2)
        {
            int x;
            cin >> x;
            val[size++] = x;
            sum += x;
        }
        if (t == 3)
        {
            sum -= val[size - 1];
            sum -= add[size - 1];
            add[size - 2] += add[size - 1];
            add[size - 1] = 0;
            size--;
        }
        cout << 1.0 * sum / size << "\n";
    }

    return 0;
}