#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

const int N = 1e6 + 5;
const long long inf = 2e18;

int used[N];
long long a, b;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool r = 0;
    cin >> a >> b;
    if (a > b) {
        r = 1;
        swap(a, b);
    }
    int sum = 0, k = 1;
    while (sum + k <= a) {
        used[k] = 1;
        sum += k;
        k++;
    }
    while (1) {
        int x = a - sum;
        int y = k;
        if (y - x > 0 && y - x <= k - 1)
        {
            used[y - x] = 0;
            used[y] = 1;
        }
        break;
    }
    for (int i = 1; i < N; i++)
        if (b >= i && !used[i])
    {
        b -= i;
        used[i] = 2;
    }
    vector<int> p, q;
    for (int i = 1; i < N; i++)
        if (used[i] == 1)
            p.pb(i);
        else
            if (used[i] == 2)
                q.pb(i);
    if (r) {
        swap(p, q);
    }
    cout << p.size() << "\n";
    for (int i = 0; i < p.size(); i++)
        cout << p[i] << ' ';
    cout << "\n";
    cout << q.size() << "\n";
    for (int i = 0; i < q.size(); i++)
        cout << q[i] << ' ';
    cout << "\n";
    return 0;
}