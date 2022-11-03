#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=5e2+20;
string s[maxn];
int x,y;
pair<int,int>test[6];
bool visited[maxn][maxn];
int n , m;
int a,b,c,d;
bool check(int a,int b)
{
    int x,y;
    for(int i = 0; i < 4; i++)
    {
        x=test[i].first+a;
        y=test[i].second+b;
        if(x == c && y == d)
            return 1;
    }
    return 0;
}
void rooham(int a, int b);
void dfs(int a,int b)
{
    visited[a][b] = 1;
    for(int i = 0 ; i < 4; i++)
    {
        x=test[i].first+a;
        y=test[i].second+b;
        if(check(a,b))
            x=c,y=d;
        if((x > -1 && x < n) && (y > -1 && y < m) && ((s[x][y] == '.') || (s[x][y] == 'X' && x == c && y == d)) && visited[x][y] == 0)
        {
            if(s[x][y] == 'X')
            {
                cout << "YES";
                exit(0);
            }
            s[x][y]='X';
            if(x == c && y == d)
            {
                rooham(x,y);
            }
            else
            {
                dfs(x,y);
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    cin >> a >> b >> c >> d;
    c--;
    d--;
    test[0].first = 1;
    test[0].second = 0;
    test[1].first = -1;
    test[1].second = 0;
    test[2].first = 0;
    test[2].second = 1;
    test[3].first = 0;
    test[3].second = -1;
    a--;
    b--;
    if(a == c && b == d)
        rooham(a,b);
    else
        dfs(a,b);
    cout << "NO";
}
void rooham(int a, int b)
{
    int x,y;
    for(int i = 0; i < 4; i++)
    {
        x=test[i].first+a;
        y=test[i].second+b;
        if((x > -1 && x < n) && (y > -1 && y < m) && (s[x][y] == '.') && visited[x][y] == 0)
        {
            cout << "YES";
            exit(0);
        }
    }
    cout << "NO";
    exit(0);
}