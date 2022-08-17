#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 200111;

int p[max_n];

int main()
{
    //ifstream cin("input.txt");
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin>>p[i];
        p[i]--;
    }

    int k1 = 0;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        k1 += a;
    }
    int ans = 0;
    if (k1 % 2 == 0) ans++;
    int kk = 0;
    bool vis[max_n] = {0};
    for (int i = 0; i < n; ++i)
    {
        if (!vis[i])
        {
            kk++;
            int cur = i;
            while (!vis[cur])
            {
                vis[cur] = true;
                cur = p[cur];
            }
        }
    }
    if (kk > 1)
    {
        ans += kk;
    }
    cout << ans;
}