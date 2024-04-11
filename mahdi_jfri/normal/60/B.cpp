#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e2+20;
string s[maxn][maxn];
pair<int,int>test[6];
int x,y;
int n , k , m;
ll res;
void prepro();
void dfs(int x,int y,int z)
{
    res++;
    s[z][x][y] = '#';
  //  cout << x << " " << y << " " << z << endl;
    for(int i = 0; i < 4; i++)
    {
        int a = test[i].first + x;
        int b = test[i].second + y;
        if((a > -1 && a < n) && (b > -1 && b < m) && (s[z][a][b] == '.'))
            dfs(a,b,z);
    }
    int z1 = z + 1;
    if((x > -1 && x < n) && (y > -1 && y < m) && (z1 < k && z1 > -1) && (s[z1][x][y] == '.'))
        dfs(x,y,z1);
    z1 = z - 1;
    if((x > -1 && x < n) && (y > -1 && y < m) && (z1 < k && z1 > -1) && (s[z1][x][y] == '.'))
        dfs(x,y,z1);
}
int main()
{
    cin >> k >> n >> m;
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < n; j++)
            cin >> s[i][j];
    }
    prepro();
    cin >> x >> y;
    x--;
    y--;
    dfs(x,y,0);
    cout << res;
  /*  for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            for(int z = 0; z < m; z++)
                cout << s[i][j][z];
            cout << endl;
        }
        cout << endl << endl;
    }*/

}
void prepro()
{
    test[0].first = 1;
    test[0].second = 0;
    test[1].first = -1;
    test[1].second = 0;
    test[2].first = 0;
    test[2].second = 1;
    test[3].first = 0;
    test[3].second = -1;
}