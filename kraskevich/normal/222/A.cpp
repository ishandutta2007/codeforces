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
#define rep(i, l, r) for (int i=l; i<r; ++i)
#define forn for(int i=0; i<n; ++i)

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;


int a[1000*1000];
int cnt[100*1000+1];
int d=0;

int main()
{
    ios_base::sync_with_stdio(0);
    
    
    int n, k;
    cin >> n >> k;
    --k;
    
    forn cin >> a[i];
    rep(i, 0, 100001) cnt[i] = 0;
    
    int res=-1;
    forn 
    {
        ++cnt[a[i]];
        if (cnt[a[i]]==1)
            ++d;
    }
    
    int cur=0;
    
    for(;;)
    {
        if (d == 1)
        {
            res = cur;
            break;
        }
        if (cur >= 100*1000*2)
            break;
        a[cur+n]=a[cur+k];
        --cnt[a[cur]];
        if (cnt[a[cur]]==0)
            --d;
        ++cnt[a[cur+n]];
        if (cnt[a[cur+n]]==1)
            ++d;
        ++cur;
    }
    
    cout << res;
    
    cin>>n;
    
    
    return 0;
}