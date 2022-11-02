#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>
 
using namespace std;
 
 
#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w;
#define ALL(x) x.begin(), x.end()
 
 
 
//-------------TEMPALTE STARTS HERE--------------//
template <class T> void read(T a, int n)
{
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}
 
template <class T> void read(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cin >> a[i];
}
 
template <class T> void print(T a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}
 
template <class T> void print(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
}
//---------------TEMPLATE ENDS HERE---------------//


const int N = 100 * 1000 + 1;
set<int> neigh[N];
set<int> was;
int col[N];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
   
    for (int i = 0; i < n; ++i)
        cin >> col[i];
    
    for (int i = 0; i < n; ++i)
        was.insert(col[i]);
    
    
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        
        --a;
        --b;
        
        if (col[a] == col[b])
            continue;
        
        neigh[col[a]].insert(col[b]);
        neigh[col[b]].insert(col[a]);
    }
    
    int mx = 0;
    for (int i = 0; i < N; ++i)
        if (neigh[i].size() > mx)
            mx = neigh[i].size();
    
    for (int i = 0; i < N; ++i)
        if (was.count(i) && neigh[i].size() == mx)
        {
            cout << i;
            return 0;
        }
}