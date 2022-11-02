
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
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>


const int mod = (int)1e9 + 7;
const int N = 1000 * 1000;

int d[N], p[N];

void init(int n)
{
    for (int i = 0; i < n; ++i)
        p[i] = i, d[i] = 0;
}

map<pii, int> ww;
int res = 0;

pii get(int v, int prev)
{
    int inc = 0;
    if (ww.count(pii(v, prev)))
    {
        inc = ww[pii(v, prev)];
        ww.erase(pii(v, prev));
    }
    
    if (v == p[v])
        return pii(v, (d[v] + inc) % mod);
        
    pii cur = get(p[v], v);
    
    d[v] += cur.S;
    d[v] %= mod;
    p[v] = cur.F;
    
    return pii(cur.F, (d[v] + inc) % mod);
}

void unite(int root, int b, int x)
{
    pii cur = get(b, -1);
    int d = (cur.S + x) % mod;
    res += d;
    res %= mod;
    b = cur.F;
    
    p[b] = root;
    ww.insert(MP(pii(root, b), d));
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
     init(n);
    
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        
        for (int j = 0; j < k; ++j)
        {
            int v, x;
            cin >> v >> x;
            
            x += mod;
            x %= mod;
            --v;
            unite(i, v, x);
        }
    }
    
    cout << res;
    
    cin >> n;
    
    return 0;
}