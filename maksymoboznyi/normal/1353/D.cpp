#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], b[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<pair<int, int> > q;
        q.insert({-n, 1});
        for (int i = 1; i <= n; i++) {
            int len = -q.begin() -> first, l = q.begin() -> second;
            int r = (l + len - 1);
            int mid = 0;
            if (len % 2 == 1)
                mid = (l + r) / 2;
            else
                mid = (l + r - 1) / 2;
            //cout << l << ' ' << r << ' ' << mid << endl;
            a[mid] = i;
            q.erase(q.begin());
            if (mid != l)
                q.insert({-(mid - l), l});
            if (mid != r)
                q.insert({-(r - mid), mid + 1});
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << "\n";
    }
    return 0;
}