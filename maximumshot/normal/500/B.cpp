#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int n;

    cin >> n;

    vec<int> p(n);
    vec< vec<int> > A(n, vec<int>(n));
    char C;

    for(int i(0);i < n;i++) cin >> p[i];

    for(int i(0);i < n;i++) for(int j(0);j < n;j++) cin >> C, A[i][j] = (C == '1');

    for(int k(0);k < n;k++)
        for(int j(0);j < n;j++)
            for(int i(0);i < n;i++)
                A[i][j] = max(A[i][j], A[i][k] & A[k][j]);

    for(int z(0);z < n;z++)
    {
        for(int i(0);i < n;i++)
        {
            int mn = n + 1, pos = -1;
            for(int j(i + 1);j < n;j++)
            {
                if(p[i] <= p[j]) continue;
                if(A[i][j] && p[j] <= mn) mn = p[j], pos = j; 
            }
            if(mn == n + 1) continue;
            swap(p[i], p[pos]);
        }
    }

    for(int i(0);i < n;i++) cout << p[i] << ' ';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}