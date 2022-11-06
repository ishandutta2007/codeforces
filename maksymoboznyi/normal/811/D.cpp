#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char d[4] = {'D', 'U', 'R', 'L'};

int n, m, xx, yy, x, y;
vector<char> way, w;
bool used[105][105];
char a[105][105];
bool check(int x, int y)
{
    return (x > 0 && y > 0 && x <= n && y <= m && a[x][y] != '*');
}
struct cell
{
    int x, y;
    vector<char> way;
};
queue<cell> q;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
         {
            cin >> a[i][j];
         }
    vector <char> u;
    u.clear();
    q.push({1, 1, u});
    used[1][1] = true;
    while (!q.empty())
    {
        x = q.front().x, y = q.front().y;
        way = q.front().way;
        q.pop();
        //cout << x << ' ' << y<<endl;
        if (a[x][y] == 'F')
            break;
        for (int i = 0; i < 4; i++)
        {
            w = way;
            xx = x + dx[i];
            yy = y + dy[i];
            if (check(xx, yy) && !used[xx][yy])
            {
                used[xx][yy] = true;
                w.pb(d[i]);
                q.push({xx, yy, w});
            }
        }
    }
    int a, b;
    if (way[0] == 'D')
    {
        cout << 'U'<<endl;
        fflush(stdout);
        cin >>a >> b;
        if (a != 1 || b != 1)
        {
            for (int i = 0; i < way.size(); i++)
                if (way[i] == 'D')
                    way[i] = 'U';
                else
                    if (way[i] == 'U')
                        way[i] = 'D';
            int i = 1, x = 2, y = 1;
            while (i < int(way.size())&&way[i] ==  'U')
            {
                cout << way[i]<<endl;
                fflush(stdout);
                cin >> a >> b;
                x++;
                i++;
            }
            if (i == way.size())
                return 0;
            cout << 'L'<<endl;
            fflush(stdout);
            cin >> a >> b;
            if (a != x || b != y)
            {
                for (int j = i; j < (int)way.size(); j++)
                    if (way[j] == 'L')
                        way[j] = 'R';
                    else
                        if (way[j] == 'R')
                            way[j] = 'L';
                for (int j = i+1; j < (int)way.size(); j++)
                 {
                     cout << way[j]<<endl;
                     fflush(stdout);
                     cin >> a >> b;
                 }
                return 0;
            }else
            {for (int j = i; j < (int)way.size(); j++)
                 {
                     cout << way[j]<<endl;
                     fflush(stdout);
                     cin >> a >> b;
                 }
                 return 0;
            }
        }
        int i = 0, x = 1, y = 1;
        while ( i < int(way.size())&& way[i] ==  'D')
        {
            cout << way[i]<<endl;
            fflush(stdout);
            cin >> a >> b;
            x++;
            i++;
        }
         if (i == way.size())
                return 0;
        cout << 'L'<<endl;
        fflush(stdout);
        cin >> a >> b;
        if (a != x || b != y)
        {
            for (int j = i; j < (int)way.size(); j++)
                if (way[j] == 'L')
                    way[j] = 'R';
                else
                    if (way[j] == 'R')
                        way[j] = 'L';
           for (int j = i+1; j < (int)way.size(); j++)
                 {
                     cout << way[j]<<endl;
                     fflush(stdout);
                     cin >> a >> b;
                 }
            return 0;
        }else
        {for (int j = i; j < (int)way.size(); j++)
                 {
                     cout << way[j]<<endl;
                     fflush(stdout);
                     cin >> a >> b;
                 }
            return 0;
        }
    }
    cout << 'L'<<endl;
    fflush(stdout);
    cin >> a >> b;
    if (a != 1 || b != 1)
    {
        int i = 1, x = 1, y = 2;
        for (int j= 0; j < (int)way.size(); j++)
             if (way[j] == 'L')
                    way[j] = 'R';
                else
                    if (way[j] == 'R')
                        way[j] = 'L';
        while (i < (int)way.size() && way[i] == 'L')
        {
            y++;
            cout << way[i]<<endl;
            fflush(stdout);
            i++;
            cin >> a>>b;
        }
        cout << 'U'<<endl;
        fflush(stdout);
        cin >> a >> b;
        if (a != x || b != y)
        {
            for (int j = i; j < (int)way.size(); j++)
                if (way[j] == 'U')
                    way[j] = 'D';
                else
                    if (way[j] == 'D')
                        way[j] = 'U';
           for (int j = i+1; j < (int)way.size(); j++)
                 {
                     cout << way[j]<<endl;
                     fflush(stdout);
                     cin >> a >> b;
                 }
            return 0;
        }
        else
        {
            for (int j = i; j < (int)way.size(); j++)
                 {
                     cout << way[j]<<endl;
                     fflush(stdout);
                     cin >> a >> b;
                 }
            return 0;
        }
    }else
    {

        int i = 0, x = 1, y = 1;
        while (i < (int)way.size() && way[i] == 'R')
        {
            y++;
            cout << way[i]<<endl;
            fflush(stdout);
            i++;
            cin >> a>>b;
        }
        cout << 'U'<<endl;
        fflush(stdout);
        cin >> a >> b;
        if (a != x || b != y)
        {
            for (int j = i; j < (int)way.size(); j++)
                if (way[j] == 'U')
                    way[j] = 'D';
                else
                    if (way[j] == 'D')
                        way[j] = 'U';
          for (int j = i+1; j < (int)way.size(); j++)
                 {
                     cout << way[j]<<endl;
                     fflush(stdout);
                     cin >> a >> b;
                 }
            return 0;
        }
        else
        { for (int j = i; j < (int)way.size(); j++)
                 {
                     cout << way[j]<<endl;
                     fflush(stdout);
                     cin >> a >> b;
                 }
            return 0;
        }
    }
    return 0;
}