#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <random>
#include <string>


#include <numeric>


#include <cmath>
#include <functional>
#include <limits>
#include <complex>


#include <queue>


#include <ostream>


 // namespace asl


 // namespace asl


 // namespace asl


 // namespace asl


 // namespace asl


 // namespace asl
 // namespace asl
 // namespace asl


#define endl '\n'

using namespace std;

const int top = 1000000000;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int mx = 0;
    int cc = -1;

    for (int i = 0; i < n; ++i)
    {
        if (i % 2 == 0)
            ++cc;
        mx += cc;
    }

    if (mx < m)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<int> b, a;

    int t = n;

    while (mx >= m + cc && t)
    {
        mx -= cc;
        b.push_back(top - (n - t) * 5002);
        if (t % 2 == 1)
        {
            cc--;
        }
        t--;
    }

    for (int i = 1; i <= t; ++i)
        a.push_back(i);

    if (mx > m)
    {
        if (a.back() % 2 == 0)
            a.back()++;
        a.back() += 2 * (mx - m);
    }

    for (auto x : a)
        cout << x << " ";
    reverse(b.begin(), b.end());
    for (auto x : b)
        cout << x << " ";
    cout << endl;

    return 0;
}