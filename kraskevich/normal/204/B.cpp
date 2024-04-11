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

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    
    cin >> n;
    
    int a[n], b[n];
    
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];
    
    map<int, int> fr, back;
    
    for (int i = 0; i < n; ++i)
    {
        if (!fr.count(a[i]))
            fr.insert(make_pair(a[i], 1));
        else
            fr[a[i]]++;
            
        if (a[i] == b[i])
            continue;
        
         if (!back.count(b[i]))
            back.insert(make_pair(b[i], 1));
        else
            back[b[i]]++;
    }
    
    int res = 1000 * 1000;
    int need = n / 2 + n % 2;
    
    for (int i = 0; i < n; ++i)
    {
        int cnt1 = fr[a[i]], cnt2 = max(0, need - cnt1);
        if (cnt2 > back[a[i]])
            continue;
        res = min(res, cnt2);
    }
    for (int i = 0; i < n; ++i)
    {
        int cnt1 = fr[b[i]], cnt2 = max(0, need - cnt1);
        if (cnt2 > back[b[i]])
            continue;
        res = min(res, cnt2);
    }
    
    cout << (res == 1000 * 1000 ? -1 : res);
        
    return 0;
}