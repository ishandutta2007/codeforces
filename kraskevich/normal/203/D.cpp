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
#define DB double

const double eps = 1e-12;

int main()
{
    ios_base::sync_with_stdio(0);
    
    int a, b, m;
    
    cin >> a >> b >> m;
    
    int vx, vy, vz;
    
    cin >> vx >> vy >> vz;
    
    vy = -vy;
    
    ///-----------------------------------------------------
    double resZ;
    if(vz == 0)
        resZ = 0;
    else
    {
        double oneZ = (DB)b / vz, t = (DB)m / vy;
        double cnt = eps + t / oneZ;
        int c = (int)cnt;
        double dz = (DB)b * (cnt - c);
        if(c % 2 == 0)
            resZ = dz;
        else
            resZ = (DB)b - dz;
        resZ = max(resZ, 0.0);
        resZ = min(resZ, (DB)b);
    }
    
    ///--------------------------------------------------
    
    int sg = -1;
    if(vx > 0)
        sg = 1;
    
    vx = max(vx, -vx);
    
    double oneX = (DB)a / vx;
    double t = (DB)m / vy;
    double resX;
    
    if(vx == 0)
        resX = (DB) a / 2;
    else
        if(oneX / 2 >= t)
        {
            double dx = 2 * t / oneX;
            resX = (DB)a / 2 + DB(sg) * (DB) a / 2.0 * dx;
        }
        else
        {
            double l = (DB)m - vy * oneX / 2;
            t = l / vy;
            double cnt1 = eps + t / oneX;
            int c1 = (int)cnt1;
            double dx = (DB)a * (cnt1 - c1);
            if(c1 % 2 == 0)
                resX = dx;
            else
                resX = (DB)a - dx;
            if(sg == 1)
                resX = (DB)a  - resX;
            resX = max(resX, 0.0);
            resX = min(resX, (DB)a);
        }
                
    //-----------------------------------------------------
    cout.setf(ios::fixed);
    cout.precision(10);
    
    cout << resX << " " << resZ;
    
    cin >> m;
    
    return 0;
}