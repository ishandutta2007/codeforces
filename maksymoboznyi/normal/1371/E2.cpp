#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, p, a[N];
vector<int> ans;

int main()
{
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 0;
    for (int i = 1; i <= n; i++)
        l = max(l, a[i] - i + 1);
    int r = 2e9;
    for (int i = 0; i + p <= n; i++)
        r = min(r, a[p + i] - i);
    r--;
    if (l > r)
        cout << 0;
    else {
        cout << r - l + 1 << "\n";
        for (int i = l; i <= r; i++)
            cout << i << ' ';
    }
    return 0;
}