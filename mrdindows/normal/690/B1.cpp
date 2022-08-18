#include <bits/stdc++.h>

using namespace std;

void fail()
{
    cout << "No\n";
    exit(0);
}

signed main()
{
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    string s[n];
    for(auto &it: s)
        cin >> it;
    int minx = n, maxx = 0, miny = n, maxy = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(s[i][j] == '4')
            {
                minx = min(minx, i);
                maxx = max(maxx, i);
                miny = min(miny, j);
                maxy = max(maxy, j);
            }
    if(minx == n)
        fail();
    for(int i = minx; i <= maxx; i++)
        for(int j = miny; j <= maxy; j++)
            if(s[i][j] != '4')
                fail();
    if(minx > 0)
        for(int j = miny; j <= maxy; j++)
            if(s[minx - 1][j] != '2')
                fail();
    if(maxx < n - 1)
        for(int j = miny; j <= maxy; j++)
            if(s[maxx + 1][j] != '2')
                fail();
    if(miny > 0)
        for(int j = minx; j <= maxx; j++)
            if(s[j][miny - 1] != '2')
                fail();
    if(maxy < n - 1)
        for(int j = minx; j <= maxx; j++)
            if(s[j][maxy + 1] != '2')
                fail();
    if(minx > 0 && miny > 0)
        if(s[minx - 1][miny - 1] != '1')
            fail();
    if(maxx < n - 1 && miny > 0)
        if(s[maxx + 1][miny - 1] != '1')
            fail();
    if(minx > 0 && maxy < n - 1)
        if(s[minx - 1][maxy + 1] != '1')
            fail();
    if(maxx < n - 1 && maxy < n - 1)
        if(s[maxx + 1][maxy + 1] != '1')
            fail();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(s[i][j] != '0' && (!(minx - 1 <= i && i <= maxx + 1) || !(miny - 1 <= j && j <= maxy + 1)))
                fail();
    cout << "Yes\n";
	return 0;
}