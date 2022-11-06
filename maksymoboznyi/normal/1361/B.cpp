#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define pi pair<int, int>

using namespace std;

const int N = 1e6 + 6;
const int M = 1e9 + 7;

int a[N], n, p;

int gp(int a, int b) {
    int res = 1;
    while (b > 0)
        if (b & 1)
            b--, res *= a, res %= M;
        else
            b /= 2, a *= a, a %= M;
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n == 1) {
            cout << gp(p, a[1]) << "\n";
            continue;
        }
        if (p == 1) {
            cout << n % 2 << "\n";
            continue;
        }
        sort(a + 1, a + n + 1);
        stack<pair<int, int> > q;
        int s1 = 0, s2 = 0;
        s2 += gp(p, a[n]);
        int ns = a[n];
        for (int i = n - 1; i >= 1; i--) {
            //cout << i << ' ' << ns << endl;
            if (ns == -1) {
                s2 += gp(p, a[i]);
                s2 %= M;
                ns = a[i];
            } else {
                s1 += gp(p, a[i]);
                s1 %= M;
                if (q.size() != 0 && a[i] == q.top().first)
                    q.top().second++;
                else
                    q.push({a[i], 1});
                while (q.top().second == p) {
                    int x = q.top().first + 1;
                    q.pop();
                    if (q.size() == 0 || q.top().first > x)
                        q.push({x, 1});
                    else
                        q.top().second++;
                }
                if (q.top().first == ns) {
                    ns = -1;
                    q.pop();
                }
            }
        }
        cout << (s2 - s1 + M) % M << "\n";

    }
    return 0;
}