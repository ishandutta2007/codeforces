#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;

const int N = 1e5 + 2;

int n, m, k;
vector<int> del[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    string s = "";
    for (int i = 1; i < m; i++)
        s += 'R';
    for (int i = 1; i < n; i++)
        s += 'D';
    int x = n, y = m;
    for (int i = n; i > 0; i--) {
        if (y == m)
            for (int j = 1; j < m; j++)
                s += 'L', y--;
        else
            for (int j = 1; j < m; j++)
                s += 'R', y++;
        if (x != 1)
            s += 'U', x--;
    }
    cout << s.size() << "\n" << s;
    return 0;
}