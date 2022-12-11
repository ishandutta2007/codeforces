//
//  main.cpp
//  spacerangers
//
//  Created by Sokol Kostya's MacBook on 01.12.11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>

using namespace std;

const double eps = 0.0000001;
const int it = 70;
const double mx = 10000;

int x[101], y[101], z[101];
double xa, ya, za;
int n;

double f(double xx, double yy, double zz);
double findz(double xx, double yy, double l, double r);
double findy(double xx, double l, double r);
void findx(double l, double r);

double f(double xx, double yy, double zz)
{
    double res = 0;
    double dx, dy, dz;
    for (int i = 0; i < n; i++)
    {
        dx = xx - x[i];
        dy = yy - y[i];
        dz = zz - z[i];
        res = max(res, dx * dx + dy * dy + dz * dz);
    }
    //cout << xx << " " << yy << " " << zz << ": " << res << "\n"; 
    return res;
}

double findz(double xx, double yy, double l, double r)
{
    for ( int i = 0; i < it; i++ )
    {
        double zz1 = l + (r - l) / 3.0;
        double zz2 = r - (r - l) / 3.0;
        double f1 = f(xx, yy, zz1), f2 = f(xx, yy, zz2);
        if (f1 < f2) r = zz2; else l = zz1;
    }
    za = l;
    return f( xx, yy, za );
}

double findy(double xx, double l, double r)
{
    for ( int i = 0; i < it; i++ )
    {
        double yy1 = l + (r - l) / 3.0;
        double yy2 = r - (r - l) / 3.0;
        double f1 = findz(xx, yy1, -mx, mx), f2 = findz(xx, yy2, -mx, mx);
        if (f1 < f2) r = yy2; else l = yy1;
    }
    //findz( xx, l, -mx, mx );
    ya = l;
    return findz( xx, ya, -mx, mx );
}

void findx(double l, double r)
{
    for ( int i = 0; i < it; i++ )
    {
        double xx1 = l + (r - l) / 3.0;
        double xx2 = r - (r - l) / 3.0;
        double f1 = findy(xx1, -mx, mx), f2 = findy(xx2, -mx, mx);
        //cout << i << " " << l << " " << r << " " << xx1 << ": " << f1 << " " << xx2 << ": " << f2 << "\n";
        if (f1 < f2) r = xx2; else l = xx1;
    }
    //findy( l, -mx, mx );
    xa = l;
}

int main (int argc, const char * argv[])
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> z[i];
    findx(-mx, mx);
    //cout << f( xa, ya, za ) << "\n";
    //cout << f( 0, 0, 0 ) << "\n";
    cout << fixed << setprecision(10) << xa << " " << ya << " " << za << "\n";
    return 0;
}