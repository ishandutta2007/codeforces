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

struct oprt
{
    int a, b, c, d;
    oprt();
    oprt(int _a, int _b, int _c, int _d): a(_a), b(_b), c(_c), d(_d) {}
};

vector<oprt> go;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    int k[n];
    for (int i = 0; i < n; ++i)
        cin >> k[i];
   
    vector<int> a[n];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < k[i]; ++j)
        {
            int num;
            cin >> num;
            a[i].PB(num);
        }

    int cnt = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < a[i].size(); ++j)
        {
            if (a[i][j] != cnt)
            {
                int wantx, wanty;
                for (int x = 0; x < n; ++x)
                    for (int y = 0; y < a[x].size(); ++y)
                        if (a[x][y] == cnt)
                            wantx = x, wanty = y;
                swap(a[i][j], a[wantx][wanty]);
                go.push_back(oprt(i + 1, j + 1, wantx + 1, wanty + 1));
            }
            ++cnt;
        }
        
    cout << go.size() << endl;
    for (int i = 0; i < go.size(); ++i)
        cout << go[i].a << " " << go[i].b << " " << go[i].c << " " << go[i].d << endl;
    
    return 0;
}