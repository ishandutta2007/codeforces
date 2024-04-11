#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<int> f(vector<int> &a, vector<int> &b)
{
    vector<int> c(a.size());

    for (int i = 0; i < a.size(); ++i)
        c[i] = a[b[i]];

    return c;
}

void show(vector<int> &a)
{
    for (auto x : a)
        cout << x << " ";
    cout << endl;
}

const int inf = 100;

int main()
{
    int n;
    cin >> n;

    vector<int> a(2 * n), b(2 * n), c(2 * n), e(2 * n);

    for (int i = 0; i < 2 * n; ++i)
    {
        cin >> a[i];
        a[i]--;
    }

    for (int i = 0; i < n; ++i)
    {
        b[2 * i] = 2 * i + 1;
        b[2 * i + 1] = 2 * i;

        c[i] = i + n;
        c[i + n] = i;

        e[i] = i;
        e[i + n] = i + n;
    }

    vector<int> x = a;
    vector<int> y = a;

    int answer = 0;

    // show(x);
    // show(y);

    while (x != e && y != e && 1. * clock() < 2.8 * CLOCKS_PER_SEC)
    {
        x = f(x, b);
        y = f(y, c);
        b.swap(c);
        answer++;

        // cout << "---" << endl;
        // show(x);
        // show(y);
    }

    if (x != e && y != e)
    {
        answer = -1;
    }

    cout << answer << endl;
}