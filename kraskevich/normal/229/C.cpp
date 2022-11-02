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
 
int main()
{
    ios_base::sync_with_stdio(0);
    
    i64 n, m;
    cin >> n >> m;
    
    vector<i64> deg(n, 0);
    i64 res = n * (n - 1) * (n - 2) / 6;
    
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        deg[a]++;
        deg[b]++;
        res -= n - 2;
    }
    
    for (int i = 0; i < n; ++i)
        res += deg[i] * (deg[i] - 1) / 2;
    
    cout << res;
    
    return 0;
}