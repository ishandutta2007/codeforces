#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    //ifstream in("input.txt");
    //ofstream out("output.txt");
    cin.tie(0), ios_base::sync_with_stdio(0), cout.precision(20), cout << fixed;
    int n, t, m;
    long double c;
    cin >> n >> t >> c;
    vector<int> a(n), times;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        times.push_back(k);
    }

    int ind = 0;
    int64_t sum = 0;
    long double algo = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        algo = (algo + a[i]) / c;
        if (i >= t)
        {
            sum -= a[i - t];
        }
        if (ind < times.size() && times[ind] == i + 1) ///i c 0
        {
            long double algo_out = algo / t;
            long double real_out = (long double)sum / t;
            cout << real_out << ' ' << algo_out << ' ' << abs(real_out - algo_out) / real_out << '\n';
            ind++;
        }
    }
    return 0;
}