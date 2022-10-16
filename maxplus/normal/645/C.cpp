#include <iostream>
#include <vector>
#define pb push_back
//#define

using namespace std;

vector<int> v;
int _am[500000], *am;

int main()
{
    int n, k, l = 0, r = 100002, m;
    string s;
    am = _am + 150000;
    cin >> n >> k >> s;++k;
    for (int i = 0; i < n; ++i)
    {
        am[i] = am[i - 1] + (s[i] == '0');
        if (s[i] == '0')
            v.pb(i);
    }
    for (int i = n; i < n + 150000; ++i)
        am[i] = am[i - 1];
    while (r - l > 1)
    {
        m = (l + r) / 2 - 1;
        int f = 0;
        for (int i = 0; i < v.size(); ++i)
            if (am[v[i] + m] - am[v[i] - m - 1] >= k)
            {
                f = 1;
                break;
            }
        if (f)
            r = m + 1;
        else
            l = m + 1;
    }
    cout << l;
    return 0;
}