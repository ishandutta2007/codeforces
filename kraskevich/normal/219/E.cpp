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

int pos[10 * 100 * 1000 + 1];

struct pst
{
    int xl, xr, x, d;
    pst() {}
    pst(int _xl, int _xr)
    {
        xl = _xl;
        xr = _xr;
        x = (xl + xr) / 2;
        d = x - xl;
    }
};

bool operator < (pst a, pst b)
{
    return a.d > b.d || a.d == b.d && a.x < b.x;
}

set<int> was;
set<pst> dx;

int main()
{
    ios_base::sync_with_stdio(0);

    
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i)
    {
        int t;
        cin >> t;
        
        if (t == 1)
        {
            int id;
            cin >> id;
            
            int cur;
            
            if (was.size() == 0)
                cur = 1;
            if (was.size() == 1)
            {
                if (*was.begin() - 1 >= n - *was.begin())
                    cur = 1;
                else
                    cur = n;
            }
            if (was.size() >= 2)
            {
                int curd = dx.begin()->d;
                cur = dx.begin()->x;
                bool e = true;
                
                set<int>::iterator ii = was.end();
                --ii;
                
                if (n - *ii > curd)
                {
                    curd = n - *ii;
                    e = false;
                    cur = n;
                }
                
                if (*was.begin() - 1 >= curd)
                {
                    e = false;
                    curd = *was.begin() - 1;
                    cur = 1;
                }
                
                if (e)
                    dx.erase(dx.begin());
            }
            
            pos[id] = cur;
            cout << cur << "\n";
            
            was.insert(cur);
            
            set<int>::iterator now = was.find(cur);
            
            if (now != was.begin())
            {
                now--;
                //cout << *now << " " << cur << endl; 
                dx.insert(pst(*now, cur));
                ++now;
            }
            ++now;
            if (now != was.end())
            {
                dx.insert(pst(cur, *now));
            }
        
        }
        else
        {
            int id;
            cin >> id;
            
            int cur = pos[id];
            
            set<int>::iterator now = was.find(cur);
            
            if (now != was.begin())
            {
                --now;
                dx.erase(pst(*now, cur));
                ++now;
            }
            ++now;
            if (now != was.end())
            {
                dx.erase(pst(cur, *now));
            }
            
            --now;
            if (now != was.begin())
            {
                now--;
                set<int>::iterator nxt = now;
                nxt++;
                nxt++;
                dx.insert(pst(*now, *nxt));
            }
            
            was.erase(cur);
        }
        
    }
    
    return 0;
}