#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector <int> son[200006];
int n;
int par[200006], color[200006];
queue <int> q;
bool used[200006];
int main()
{
    cin >> n;
    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        son[x].pb(y);
        son[y].pb(x);
    }
    par[1] = 0;
    color[0] = 0;
    color[1] = 1;
    int c = 1;
    q.push(1);
    used[1] = true;
    par[1] = 0;

    while (!q.empty())
    {
        int i = q.front();
        q.pop();
        int p = 1;
       // cout << i;
        //cout << i << ' ' << son[i].size();
        for (int j = 0; j < son[i].size(); j++)
        if (!used[son[i][j]])
        {
            par[son[i][j]] = i;
            //cout << son[i][j] << endl;
            while (p == color[i] || p == color[par[i]])
                p++;
            color[son[i][j]] = p;
            //cout << i << ' ' << son[i][j] << ' ' << p;
            p++;
            used[son[i][j]] = true;
            q.push(son[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
        c = max(c, color[i]);
    cout << c << endl;
    for (int i = 1; i <= n; i++)
        cout << color[i] << ' ' ;
    return 0;
}