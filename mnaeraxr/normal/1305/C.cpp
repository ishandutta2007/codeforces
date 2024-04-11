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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if (n > m)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    long long x = 1;

    for (int i = 0; i < n && x; ++i)
    {
        for (int j = i + 1; j < n && x; ++j)
        {
            x = x * abs(a[i] - a[j]) % m;
        }
    }

    cout << x << endl;

    return 0;
}