#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int max_n = 200005;

vector<int> m;
bool ex[2 * max_n];

int main()
{
    int ans = 0, kol0 = 0, a, n, gl;
    cin >> n >> gl;
    gl--;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        if (i == gl && a != 0)
        {
            ans++;
            a = 0;
        }
        if (a == 0)
        {

            if (i != gl)
            {
                kol0++;
            }
        }
        else
        {
            m.push_back(a);
            ex[a] = true;
        }
    }
    ans += kol0;
    int maxx = 1;
    for (maxx = 1; kol0 > 0; maxx++)
    {
        if (ex[maxx]) continue;
        ex[maxx] = true;
        kol0--;
    }
    sort(m.begin(), m.end());
    n = m.size();
    for (int i = 0; i < n; i++)
    {
        if (m[i] <= maxx)
        {
            maxx = max(maxx, m[i] + 1);
            continue;
        }

        int d = m[i] - maxx;
        int ost = n - i;
        if (ost <= d)
        {
            m[i] = maxx;
            maxx++;
            ans++;
            continue;
        }
        else
        {
            ans += d;
            n -= d;
            maxx = m[i] + 1;
        }
    }
    cout << ans;
}