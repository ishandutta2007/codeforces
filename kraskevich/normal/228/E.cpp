#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>

typedef long long i64;


const int N = 111;
int no[N][N];
vector<bool> u(N, false);
int c[N];
int yes[N][N];
int n;
bool ok = true;

void dfs(int v, int col)
{
    if (!ok)
        return;
    
    c[v] = col;
    
    for (int i = 0; i < n; ++i)
        if (yes[v][i] && c[i] == 0)
        {
            //cout << v << " " << i << endl;
            dfs(i, col);
        }
    
    for (int i = 0; i < n; ++i)
        if (c[i] == 0 && no[v][i])
        {
            //cout << "bit" <<  v <<  " " << i << endl;
            dfs(i, col == 1 ? 2 : 1);
        }
}

vector<vector<int> > comp;
vector<int> cur;

void dfs2(int v)
{
    cur.push_back(v);
    u[v] = true;
    
    for (int i = 0; i < n; ++i)
        if (!u[i] && yes[v][i])
            dfs2(i);
}

vector<int> ans;

int sol(vector<int> a)
{
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < a.size(); ++i)
        if (c[a[i]] == 1)
            ++cnt1;
        else
            ++cnt2;
    
    if (cnt1 < cnt2)
    {
        for (int i = 0; i < a.size(); ++i)
            if (c[a[i]] == 1)
                ans.push_back(a[i]);
    }
    else
    {
        for (int i = 0; i < a.size(); ++i)
            if (c[a[i]] == 2)
                ans.push_back(a[i]);
    }
}
    

int main()
{
    ios_base::sync_with_stdio(0);
    
    int m;
    cin >> n >> m;
    
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            yes[i][j] = no[i][j] = 0;
    for (int i = 0; i < N; ++i)
        c[i] = 0;
            
    for (int i = 0; i < m; ++i)
    {
        int a, b, e;
        
        cin >> a >> b >> e;
        
        --a;
        --b;
        if (e)
            yes[a][b] = yes[b][a] = true;
        else
            no[a][b] = no[b][a] = 1;
    }
    
    
    for (int i = 0; i < n; ++i)
        if (c[i] == 0)
            dfs(i, 1);
    
    /*for (int i = 0; i < n; ++i)
        cout << c[i] << " ";
    cout << endl;*/
    
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            if (c[i] == c[j] && no[i][j])
                ok = false;
            if (c[i] != c[j] && yes[i][j])
                ok = false;
        }
    
    if (!ok)    
    {
        cout << "Impossible";
        //cin >> n;
        return 0;
    }
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            yes[i][j] = (yes[i][j] || no[i][j]);
            
    for (int i = 0; i < n; ++i)
        if (!u[i])
        {
            cur.clear();
            dfs2(i);
            comp.push_back(cur);
        }

    for (int i = 0; i < comp.size(); ++i)
        sol(comp[i]);
    
    
    
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i] + 1 << " ";
    cout << endl;
    
    //cin >> n;
        

    return 0;
}