#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long i64;
#define sqr(a) (a) * (a)
#define S second
#define F first
#define MP make_pair
#define PB push_back

i64 f[60][60][61];
i64 d[60][60][60];
i64 one[60][60];
const i64 inf = 1e18;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n, m, r;
    
    cin >> n >> m >> r;
    for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                    for(int k = 0; k < n; ++k)
                            cin >> d[i][j][k];
    
    for(int car = 0; car < m; ++car)
            for(int k = 0; k < n; ++k)
                    for(int i = 0; i < n; ++i)
                            for(int j = 0; j < n; ++j)
                                    d[car][i][j] = min(d[car][i][j], d[car][i][k] + d[car][k][j]);
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    one[i][j] = inf; 
    for(int car = 0; car < m; ++car)
            for(int i = 0; i < n; ++i)
                    for(int j = 0; j < n; ++j)
                            one[i][j] = min(one[i][j], d[car][i][j]);
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    for(int k = 0; k <= 60; ++k)
                            f[i][j][k] = one[i][j];
    for(int c = 1; c <= 60; ++c)
            for(int k = 0; k < n; ++k)
                    for(int i = 0; i < n; ++i)
                            for(int j = 0; j < n; ++j)
                            {
                                    f[i][j][c] = min(f[i][j][c], f[i][j][c - 1]);
                                    f[i][j][c] = min(f[i][j][c], f[i][k][c - 1] + one[k][j]); 
                            }
    
    for(int i = 0; i < r; ++i)
    {
            int s, t, k;
            cin >> s >> t >> k;
            
            if(k > 60)
                 k = 60;
            
            --s, --t;
            cout << f[s][t][k] << endl;
    }
    
    return 0;
}