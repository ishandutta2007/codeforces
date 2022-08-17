#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;

int main()
{
    int n;
    cin >> n;
    int m[max_n];
    for (int i = 0; i < n; ++i)
    {
        cin >> m[i];
    }
    sort(m, m + n);
    int finish = -1, start = -1;
    for (int i = 1; i < n; ++i)
    {
        if (m[i] > m[i - 1])
        {
            start = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; --i)
    {
        if (m[i] < m[i + 1])
        {
            finish = i;
            break;
        }
    }
    if (start == -1)
    {
        cout << 0;
        return 0;
    }
    cout << finish - start + 1;
    return 0;
}