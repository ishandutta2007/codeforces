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
const double eps = 1e-7;
const int inf = (int)1e9;

double sqr(double a)
{
    return a * a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    int x[n];
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    
    int m;
    cin >> m;
    
    int y[m];
    for (int i = 0; i < m; ++i)
        cin >> y[i];
    
    int k;
    cin >> k;
    
    int z[k];
    for (int i = 0; i < k; ++i)
        cin >> z[i];
    
    int a, b;
    cin >> a >> b;
    
    int r1 = x[0];
    for (int i = 1; i < n; ++i)
        r1 = max(r1, x[i]);
    
    int p1 = y[0];
    for (int i = 1; i < m; ++i)
        p1 = max(p1, y[i]);
    
    int p2 = z[0];
    for (int i = 0; i < k; ++i)
        p2 = min(p2, z[i]);
    
    double l = 0, r = r1;
    
    for (int i = 0; i < 500; ++i)
    {
        double m = (l + r) / 2;
        double in = sqr(m) * p2;
        double out = sqr((double)r1) * p1 - sqr(m) * p1;
        
        if (out * b > in * a)
            l = m;
        else
            r = m;
    } 
    
    cout.setf(ios::fixed);
    cout.precision(15);
    
    cout << l;
    
            
    
    return 0;
}