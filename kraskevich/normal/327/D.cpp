#include <algorithm>
#include <iostream>
#include <string.h>
#include <memory.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define PII pair<int, int>
#define F first
#define S second
#define ALL(x) x.begin(), x.end()
#define SZ(x) ((int)x.size())
#define div __div__
#define hash __hash__
#define prev __prev__
#define left __left__
#define right __right__
#define link __link__
#define next __next__

typedef long long LL;
typedef unsigned int UI;
typedef unsigned long long ULL;


const int N = 500 + 10;
string s[N];
vector<int> xx, yy;
vector<char> c;
int n, m;

bool good(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m && s[i][j] == '.';
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, bool nn)
{
    s[x][y] = '#';
    xx.push_back(x);
    yy.push_back(y);
    c.push_back('B');
    for (int r = 0; r < 4; r++)
    {
        int i = x + dx[r];
        int j = y + dy[r];
        if (good(i, j))
            dfs(i, j, false);
    }
    if (nn)
        return;
    xx.push_back(x);
    yy.push_back(y);
    c.push_back('D');
    xx.push_back(x);
    yy.push_back(y);
    c.push_back('R');
}


int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (good(i, j))
                dfs(i, j, true);
    cout << c.size() << endl;
    for (int i = 0; i < c.size(); i++)
        cout << c[i] << " " << xx[i] + 1 << " " << yy[i] + 1 << endl;

    return 0;
}