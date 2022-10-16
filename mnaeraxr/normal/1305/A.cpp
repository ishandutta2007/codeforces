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


using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i + 1 == n];
        for (int i = 0; i < n; ++i)
            cout << b[i] << " \n"[i + 1 == n];
    }

    return 0;
}