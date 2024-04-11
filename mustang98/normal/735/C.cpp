#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200008;

int main()
{
    ll n;
    cin >> n;
    ll m[max_n];
    m[0] = 0;
    m[1] = 1;
    for (int i = 2; i < 1000; i++)
    {
        m[i] = m[i - 1] + m[i - 2] + 1;
        if (m[i] >= n)
        {
            cout << i - 1;
            return 0;
        }
    }
    return 0;
}