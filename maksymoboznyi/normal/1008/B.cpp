#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const long long inf = 2e18;
const int N = 1e5+5;

int n, w[N], h[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> h[i];
    int cur = 2e9;
    for (int i = 1; i <= n; i++)
    {
        if (w[i] > h[i])
            swap(w[i], h[i]);
        if (h[i] <= cur)
            cur = h[i];
        else
            if (w[i] <= cur)
                cur = w[i];
            else
            {
                cout << "No";
                return 0;
            }
    }
    cout << "Yes";
    return 0;
}