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
    
    int na, ma;
    cin >> na >> ma;
    
    string a[na];
    for (int i = 0; i < na; ++i)
        cin >> a[i];
    
    int nb, mb;
    cin >> nb >> mb;
    
    string b[nb];
    for (int i = 0; i < nb; ++i)
        cin >> b[i];
    
    int res = 0, x = 0, y = 0;
    
    for (int xx = -50; xx <= 50; ++xx)
        for (int yy = -50; yy <= 50; ++yy)
        {
            int cur = 0;
            for (int i = 0; i < na; ++i)
                for (int j = 0; j < ma; ++j)
                    if (i + xx >= 0 && i + xx < nb && j + yy < mb && j + yy >= 0)
                        cur += (int)(a[i][j] - '0') * (b[i + xx][j + yy] - '0');
            
            if (cur > res)
            {
                res = cur;
                x = xx;
                y = yy;
            }
        }
    
    cout << x << " " << y << endl;
    
    //cin >> x;
        
    
    return 0;
}