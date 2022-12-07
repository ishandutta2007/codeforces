#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <math.h>

#define endl '\n'

using namespace std;

typedef complex<long long> point;

long long cross(point a, point b)
{
    return imag(conj(a) * b);
}

long long dot(point a, point b) { return real(conj(a) * b); }

// bool compare(point pivot, point a, point b)
// {
//     auto cur = cross(a - pivot, b - pivot);
//     if (cur != 0)
//         return cur > 0;
//     return dot(a - pivot, a - pivot) < dot(b - pivot, b - pivot);
// }

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<point> c(n);

    long double theta = 1;
    point rot(cos(theta), sin(theta));

    cout.precision(12);
    // cout << fixed;

    // cout << real(rot) << " " << imag(rot) << endl;

    for (int i = 0; i < n; ++i)
    {
        long double x, y;
        cin >> x >> y;
        c[i] = {x, y};
        // c[i] *= rot;

        // cout << real(c[i]) << " " << imag(c[i]) << endl;
    }

    vector<int> order = {0, 1};

    for (int i = 2; i < n; ++i)
    {
        order.push_back(i);

        int j = i - 1;
        while (j > 0 && dot(c[order[j - 1]] - c[order[j]], c[order[j + 1]] - c[order[j]]) <= 0)
        {
            swap(order[j], order[j + 1]);
            --j;
        }
    }

    // for (int i = 0; i < n; ++i)
    //     order[i] = i;

    // sort(order.begin(), order.end(), [&](auto u, auto v) { return real(c[u]) < real(c[v]); });

    // vector<int> sol;

    // int b = 0, e = n;
    // while (b < e)
    // {
    //     sol.push_back(order[b++] + 1);

    //     if (b < e)
    //     {
    //         sol.push_back(order[--e] + 1);
    //     }
    // }

    // for (auto x : order)
    //     cout << x + 1 << " ";
    // cout << endl;

    // const long long inf = 1000000000 + 1;

    // vector<bool> used(n);
    // point prev(inf, inf);
    // vector<int> sol;

    // for (int i = 0; i < n; ++i)
    // {
    //     int t = -1;

    //     for (int j = 0; j < n; ++j)
    //     {
    //         if (used[j])
    //             continue;

    //         if (t == -1 || compare(prev, c[j], c[t]))
    //         {
    //             t = j;
    //         }
    //     }

    //     used[t] = true;
    //     sol.push_back(t + 1);
    //     prev = c[t];
    // }

    for (auto x : order)
        cout << x + 1 << " ";
    cout << endl;

    return 0;
}