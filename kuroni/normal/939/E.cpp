#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<long long> s;
int q, t, x;

double find_ans()
{
    if (s.size() == 2)
        return 0;
    int n = s.size() - 1, l = 1, r = n - 1, m;
    long long mea, exp;
    while (l <= r)
    {
        m = (l + r) / 2;
        mea = s[n] - s[n - 1] + s[m];
        exp = (s[m] - s[m - 1]) * (m + 1);
        if (exp <= mea)
            l = m + 1;
        else r = m - 1;
    }
    return s[n] - s[n - 1] - 1.0 * (s[n] - s[n - 1] + s[r]) / (r + 1);
}

int main()
{
    scanf("%d", &q);
    s.push_back(0);
    while (q--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d", &x);
            s.push_back(s.back() + x);
        }
        else
            printf("%.6f\n", find_ans());
    }
}