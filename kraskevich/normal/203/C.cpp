#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
using namespace std;

typedef long long i64;
#define MP make_pair
#define F first
#define S second
#define FORN for(int i = 0; i < n; ++i)
#define PB push_back
#define REP(i, l, r) for(int i = l; i <= r; ++i)

i64 a, b;

struct cln
{
    i64 x, y, id;
    cln(int xx = 0, int yy = 0, int i = 0)
    {
        x = xx;
        y = yy;
        id = i;
    }
};

bool cmp(cln c1, cln c2)
{
    return c1.x * a + c1.y * b < c2.x * a + c2.y * b;
}

cln c[1000000];

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    i64 d;
    
    cin >> n >> d;
    cin >> a >> b;
    
    for(int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        c[i] = cln(x, y, i + 1);
    }
    
    sort(c, c + n, cmp);
    
    vector<int> res;
    
    for(int i = 0; i < n; ++i)
    {
        i64 cur = c[i].x * a + c[i].y * b;
        if(d - cur >= 0)
        {
            res.push_back(c[i].id);
            d -= cur;
        }
        else
            break;
    }
    
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    
    cin >> n;
    
    return 0;
}