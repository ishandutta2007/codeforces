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
#define REP(i, l, r) for (int i = l; i < r; ++i)
#define REPDOWN(i, r, l) for (int i = r; i >= l; --i)
#define FORN for (int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define PB push_back
 
typedef long long i64;

const int N = 100 * 1000;
int h[N], m[N];


int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int res = 0, cur = 0;
    
    FORN
    {
        cin >> h[i] >> m[i];
        
        if (i && h[i] == h[i - 1] && m[i] == m[i - 1])
            ++cur;
        else
            cur = 1;
        res = max(res, cur);
    }
    
    cout << res;
    
    return 0;
}