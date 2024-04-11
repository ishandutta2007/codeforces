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
#define WAIT int w; cin >> w
#define ALL(x) x.begin(), x.end()

const int N = 100 * 1000;
vector<int> g[N];
PII edge[N];
int n, m, h, t;
int a[N], b[N];
int sza, szb;

int getSame()
{
    int aa = 0, bb = 0, res = 0;
    for (;;)
    {
        if (aa == sza || bb == szb)
            break;
        while (bb < szb && b[bb] < a[aa])
            ++bb;
        if (bb < szb && b[bb] == a[aa])
            ++res;
        ++aa;
    }
    return res;
}

void print(int from, int to)
{
    set<int> head, tail, was;
    for (int i = 0; i < g[from].size();  ++i)
        if (g[from][i] != to)
            head.insert(g[from][i]);
    for (int i = 0; i < g[to].size(); ++i)
        if (g[to][i] != from)
            tail.insert(g[to][i]);
    set<int> same;
    for (set<int>::iterator it = head.begin(); it != head.end(); ++it)
        if (tail.count(*it))
            same.insert(*it);
    for (set<int>::iterator it = same.begin(); it != same.end(); ++it)
        head.erase(*it);
        

    cout << "YES" << endl;
    
    cout << from + 1 << " " << to + 1 << endl;
    
    int cnt = 0;
    for (set<int>::iterator it = head.begin(); it != head.end() && cnt < h; ++it, ++cnt)
        cout << *it + 1 << " ";
    for (set<int>::iterator it = same.begin(); it != same.end() && cnt < h; ++it, ++cnt)
    {
        was.insert(*it);
        cout << *it + 1 << " ";
    }
    cout << endl;
    
    cnt = 0;
    for (set<int>::iterator it = tail.begin(); it != tail.end() && cnt < t; ++it)
    {
        if (was.count(*it))
            continue;
        ++cnt;
        cout << *it + 1 << " ";
    }

}
        
int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n >> m >> h >> t;
    
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        
        --a;
        --b;
        
        g[a].push_back(b);
        g[b].push_back(a);
        edge[i] = PII(a, b);
    }
    
    for (int i = 0; i < n; ++i)
        sort(g[i].begin(), g[i].end());
    
    for (int it = 0; it < m; ++it)
    {
        int head = edge[it].F, tail = edge[it].S;
        int curh = g[head].size() - 1, curt = g[tail].size() - 1;
        sza = szb = 0;
        
        for (int i = 0; i < min((int)g[head].size(), 200); ++i)
            a[sza++] = g[head][i];
        for (int i = 0; i < min((int)g[tail].size(), 200); ++i)
            b[szb++] = g[tail][i];
        
        int same = getSame();
        curh -= same;
        curt -= same;
        int wanth = max(0, h - curh);
        int wantt = max(0, t - curt);
        
        if (same >= wanth + wantt)
        {
            print(head, tail);
            return 0;
        }
    }
    
    for (int i = 0; i < m; ++i)
        swap(edge[i].F, edge[i].S);
    
    for (int it = 0; it < m; ++it)
    {
        int head = edge[it].F, tail = edge[it].S;
        int curh = g[head].size() - 1, curt = g[tail].size() - 1;
        sza = szb = 0;
        
        for (int i = 0; i < min((int)g[head].size(), 200); ++i)
            a[sza++] = g[head][i];
        for (int i = 0; i < min((int)g[tail].size(), 200); ++i)
            b[szb++] = g[tail][i];
        
        int same = getSame();
        curh -= same;
        curt -= same;
        int wanth = max(0, h - curh);
        int wantt = max(0, t - curt);
        
        if (same >= wanth + wantt)
        {
            print(head, tail);
            return 0;
        }
    }
    
    cout << "NO";
    
    return 0;
}