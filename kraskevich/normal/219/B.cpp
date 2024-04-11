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


int main()
{
    ios_base::sync_with_stdio(0);
    
    long long d, p;
    cin >> d >> p;
    
    long long r = d, l = d - p;
    ++l;
    ++r;
    
    long long cur = 10;
    long long res = r - 1;
    
    for (;;)
    {
        long long lo = 0, hi = r / cur + 1;
        
        if (hi == 0)
            break;
        
        while (lo < hi)
        {
            long long m = (lo + hi + 1) / 2;
            
            if (m * cur > r)
                hi = m - 1;
            else
                lo = m;
        
        }
        
        if (lo * cur <= r && lo * cur >= l && lo * cur > 0)
            res = lo * cur - 1;
        
        if (cur == (long long)1e18)
            break;
            
        cur *= 10ll;
    }
    
    cout << res;
    
    return 0;
}