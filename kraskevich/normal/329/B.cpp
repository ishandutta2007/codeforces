#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <string.h>
#include <cctype>
#include <fstream>

using namespace std;


//-----TEMPLATE STARTS HERE------//
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, long long> PIL;
typedef pair<long long, int> PLI;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef long double LD;

#define MP make_pair
#define PB push_back
#define hash __hash__
#define left __left__
#define right __right__
#define link __link__
#define div __div__
#define next __next__
#define y0 y1005000
#define y1 y1005001
#define F first
#define S second
//-----TEMPLATE ENDS HERE------//
//--ACTUAL SOLUTION IS BELOW---//

const int N = 1111;
const int INF = 1000 * 1000 * 1000;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1,  0, 0};

string s[N];
int d[N][N];
queue<PII> q;
int n, m;

bool good(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return s[i][j] != 'T';
}

int func(int i, int j)
{
    if (s[i][j] <= '9' && s[i][j] >= '0')
        return s[i][j] - '0';
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifndef ONLINE_JUDGE
        freopen("in.cpp", "r", stdin);
        //freopen("out.cpp", "w", stdout);
    #endif

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            d[i][j] = INF;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'E')
            {
                d[i][j] = 0;
                q.push(PII(i, j));
            }
    while (!q.empty())
    {
        int x = q.front().F;
        int y = q.front().S;
        q.pop();
        for (int rep = 0; rep < 4; rep++)
        {
            int xx = x + dx[rep];
            int yy = y + dy[rep];
            if (good(xx, yy) && d[xx][yy] > d[x][y] + 1)
            {
                d[xx][yy] = d[x][y] + 1;
                q.push(PII(xx, yy));
            }
        }
    }
    int dist = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (s[i][j] == 'S')
                dist = d[i][j];
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (d[i][j] <= dist)
                res += func(i, j);

    cout << res;

    return 0;
}