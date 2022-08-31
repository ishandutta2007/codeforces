#include <iostream>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <stack>
#include <map>
#include <queue>

#define F first
#define S second
#define x1 privet1
#define x2 privet2
#define y1 privet3
#define y2 privet4

using namespace std;
typedef long long ll;


int n, root = 0;
vector<int> v[200001];
int tin[200001], tout[200001];

int p[200001][25];
int d[200001];

int current = 0, u = 0, w = 0, curd = 0;

void dfs(int a, int depth)
{
    d[a] = depth;
    current++;
    tin[a] = current;
    for(int i = 0; i < v[a].size(); i++)
        dfs(v[a][i], depth + 1);
    current++;
    tout[a] = current;
}

void dfs1(int a)
{
    int cur = 0;
    if(p[a][0] == -1) goto m1;
    while(p[p[a][cur]][cur] != -1)
    {
        p[a][cur + 1] = p[p[a][cur]][cur];
        cur++;
    }
    m1:
    for(int i = 0; i < v[a].size(); i++)
        dfs1(v[a][i]);
}

bool isanc(int a, int b)
{
    if (a == -1) return true;
    if (tin[a] < tin[b] && tout[a] > tout[b]) return true;
    return false;
}

int diametr(int a, int b)
{
    if (isanc(a, b) || isanc(b, a)) return abs(d[a] - d[b]);
    //p[a][l]  
    int l = 20;
    int pr = a;
    while(l)
    {
        if (isanc(p[pr][l - 1], b)) l--;
        else pr = p[pr][l - 1];
    }
    return d[a] - d[p[pr][0]] + d[b] - d[p[pr][0]];
}

int main()
{
    int a;
    cin>>n;
    p[0][0] = -1;
    for(int i = 1; i < n; i++)
    {
        cin>>a;
        a--;
        v[a].push_back(i);
        p[i][0] = a;
    }
    dfs(root, 0);
    for(int i = 0; i < n; i++)
        for(int j = 1; j < 20; j++) p[i][j] = -1;
    dfs1(root);
    for(int i = 1; i < n; i++)
    {
        int newd1 = diametr(w, i);
        int newd2 = diametr(u, i);
        if (newd1 > newd2)
        {
            if (newd1 > curd)
            {
                u = i;
                curd = newd1;
            }
        }
        else
        {
            if (newd2 > curd)
            {
                w = i;
                curd = newd2;
            }
        }
        cout<<curd<<'\n';
    }
    return 0;
}
/*

*/