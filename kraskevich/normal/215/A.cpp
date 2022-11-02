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

int main()
{
    ios_base::sync_with_stdio(false);
    
    int n, m;
    
    cin >> n;
    
    int a[n];
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    cin >> m;
    
    int b[m];
    
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    
    int mx = -1;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (b[j] % a[i])
                continue;
            mx = max(mx, b[j] / a[i]);
        }
    
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (b[j] % a[i] == 0 && b[j] / a[i] == mx)
                ++cnt;
        }
    
    cout << cnt;
    
            
    
    return 0;
}