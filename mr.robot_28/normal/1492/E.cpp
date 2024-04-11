#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ld long double
#define sz(s) (int)s.size()
int n, m;
const int N = 3e5;
vector <int> a[N];
int dif[N];
int ans[N];
void print()
{
    cout << "Yes\n";
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
bool check()
{
    int f = 1;
    for(int i = 2; i <= n; i++)
    {
        int cnt = 0;
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] != ans[j])
            {
                cnt++;
            }
        }
        if(cnt > 2)
        {
            f = 0;
        }
    }
    return f;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        a[i].resize(m + 10);
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    int max_dif = 0;
    int id3 = 0, id4 = 0;
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] != a[1][j])
            {
                dif[i]++;
            }
        }
        max_dif = max(max_dif, dif[i]);
        if(dif[i] == 3)
        {
            id3 = i;
        }
        if(dif[i] == 4)
        {
            id4 = i;
        }
    }
    if(max_dif >= 5)
    {
        cout << "No";
        return 0;
    }
    if(max_dif <= 2)
    {
        for(int i = 1; i <= m; i++)
        {
            ans[i] = a[1][i];
        }
        print();
        return 0;
    }
    if(id3 != 0)
    {
        vector <int> p;
        for(int j = 1; j <= m; j++)
        {
            ans[j] = a[1][j];
            if(a[1][j] != a[id3][j])
            {
                p.push_back(j);
            }
        }
        for(int x = 0; x < 3; x++)
        {
            ans[p[x]] = a[id3][p[x]];
            if(check())
            {
                print();
                return 0;
            }
            ans[p[x]] = a[1][p[x]];
        }
        for(int x = 0; x < 3; x++)
        {
            for(int y = x + 1; y < 3; y++)
            {
                ans[p[x]] = a[id3][p[x]];
                ans[p[y]] = a[id3][p[y]];
                if(check())
                {
                    print();
                    return 0;
                }
                ans[p[x]] = a[1][p[x]];
                ans[p[y]] = a[1][p[y]];
            }
        }
        for(int x =0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                ans[p[x]] = a[id3][p[x]];
                int pp = 0;
                for(int i = 2; i <= n; i++)
                {
                    if(i == id3)
                    {
                        continue;
                    }
                    int cnt = 0;
                    for(int j = 1; j <= m; j++)
                    {
                        if(j != p[y] && ans[j] != a[i][j])
                        {
                            cnt++;
                        }
                    }
                    if(cnt == 2)
                    {
                        pp = i;
                    }
                }
                if(pp != 0)
                {
                    ans[p[y]] = a[pp][p[y]];
                    if(check())
                    {
                        print();
                        return 0;
                    }
                    ans[p[y]] = a[1][p[y]];
                }
                ans[p[x]] = a[1][p[x]];
            }
        }
    }
    else if(id4 != 0)
    {
        vector <int> p;
        for(int j = 1; j <= m; j++)
        {
            ans[j] = a[1][j];
            if(a[1][j] != a[id4][j])
            {
                p.push_back(j);
            }
        }
        for(int i = 0; i < 4; i++)
        {
            for(int j = i + 1; j < 4; j++)
            {
                ans[p[i]] = a[id4][p[i]];
                ans[p[j]] = a[id4][p[j]];
                if(check())
                {
                    print();
                    return 0;
                }
                ans[p[i]] = a[1][p[i]];
                ans[p[j]] = a[1][p[j]];
            }
        }
    }
    cout << "No";
    return 0;
}