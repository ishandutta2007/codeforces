#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define x first
#define y second
using namespace std;


const int N = 1005;

int n;
pair<int, int> a[N], b[N];

map<pair<int, int>, int> m;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= n; i++)
        cin >> b[i].x >> b[i].y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            m[b[j]] = 0;
        for (int j = 1; j <= n; j++)
            m[b[j]]++;
        m[b[i]]--;
        bool r = 1;
        pair<int, int> cur = {a[1].x + b[i].x, a[1].y + b[i].y};
      //  cout << cur.x << ' ' << cur.y << endl;
        for (int j = 2; j <= n; j++) {
            pair<int, int> c1 = {cur.x - a[j].x, cur.y - a[j].y};
           // cout << c1.x << ' ' << c1.y << endl;
            if (m[c1] != 0)
                m[c1]--;
            else {
                r = 0;
                break;
            }
        }
        if (r) {
            cout << cur.x << ' ' << cur.y;
            return 0;
        }
    }
    return 0;
}