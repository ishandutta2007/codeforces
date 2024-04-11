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
#define ALL(x) x.begin(), x.end()
#define PB push_back

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;



//---------------------------------------//
//Reading and printing arrays and vectors//
template<class T> void read(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cin >> a[i];
}

template<class T> void read(T a[], int n)
{
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

template<class T> void print(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << "\n";
}

template<class T> void print(T a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}

void wait()
{
    int w;
    cin >> w;
}
//-----------------------------------------//

const int N = 200 * 1000 + 2;

vector<int> g[N];
vector<bool> u(N, false);
vector<int> up(N, 0);
vector<int> bad(N, 0);
vector<int> anc(N, 0);
vector<int> h(N);

set<pii> e;

void dfs(int v, int b, int hh)
{
    u[v] = true;
    
    bad[v] = b;
    h[v] = hh;
    
    for (int i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (!u[to])
        {
            dfs(to, e.count(pii(v, to)) ? b + 1 : b, hh + 1);
        
            if (!e.count(pii(v, to)))
                up[v]++;
            up[v] += up[to];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; ++i)
    {
        int f, t;
        cin >> f >> t;
        
        --f;
        --t;
        
        g[f].push_back(t);
        g[t].push_back(f);
        e.insert(pii(f, t));
    }
    
    dfs(0, 0, 0);
    
    int mn = inf;
    for (int i = 0; i < n; ++i)
        mn = min(mn, up[0] - (h[i] - bad[i]) + bad[i]);
    
    cout << mn << endl;
    for (int i = 0; i < n; ++i)
        if (up[0] - (h[i] - bad[i]) + bad[i] == mn)
            cout << i + 1 << " ";
   
    return 0;
}