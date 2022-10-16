#include <iostream>
#include <vector>
#include <ctime>
#include <functional>
#include <queue>
#include <random>

using namespace std;

int main()
{
    std::uniform_real_distribution<long double> dist(0, 1);
    std::random_device rd;
    std::mt19937 e2(rd());

    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    long double alpha = 0.8;

    cout.precision(4);
    cout << fixed;

    int my_error = 0;

    for (int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;

        vector<long double> acc(n);
        long double x = 0;

        int cm = *min_element(c.begin(), c.end());

        cerr << my_error << "/" << cm << "/" << i << endl;

        for (int j = 0; j < n; ++j)
        {
            x += expl(-alpha * (c[j] - cm));
            acc[j] = x;
        }

        long double selected = dist(e2) * x;

        int ix = 0;
        while (selected > acc[ix] && ix + 1 < n)
            ix++;

        cout << s[ix] << endl;
        cout.flush();

        int ans;
        cin >> ans;

        if (s[ix] - '0' != ans)
            my_error++;

        for (int j = 0; j < n; ++j)
            if (s[j] - '0' != ans)
                c[j]++;
    }

    int they_err = *min_element(c.begin(), c.end());
    double expected = 1.3 * they_err + 100;
    cerr << my_error << " " << they_err << " " << expected << endl;
}