#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

double a, v, l, d, w;

double timeneed(double v0, double v1) {
    return abs(v0-v1) / a;
}

double getlen( double v0, double v1, double time) {
    return (v0 + v1) * time / 2;
}

double solve( double b, double len) {
    double t = timeneed( b, v);
    double qd = getlen( b, v, t);
    if(qd <= len) return t + (len - qd) / v;
    else {
        double L = 0, R = 1e6;
        for(int kk=0;kk<55;++kk) {
            double M = (L+R) / 2;
            double z = M * b + a * M * M  / 2;
            if(z > len) R = M;
            else L = M;
        }
        return L;
    }
}

int main() {
    cin >> a >> v >> l >> d >> w;
    if( w >= v) {
        double lenv = timeneed( 0, v);
        double qd = getlen( 0, v, lenv);
        if(qd <= l) {
            printf("%.6f\n", (l-qd) / v + lenv);
        }
        else {
            printf("%.6f\n", sqrt(2 * l / a));
        }   
    }
    else {
        double lenw = timeneed( 0, w);
        double qd = getlen( 0, w, lenw);
        if(qd > d) {
            double lenv = timeneed( 0, v);
            qd = getlen( 0, v, lenv);
            if(qd <= l) {
                printf("%.6f\n", (l-qd) / v + lenv);
            }
            else {
                printf("%.6f\n", sqrt(2 * l / a));
            }   
        }   
        else {
            double z = getlen(0, v, timeneed( 0, v)) + getlen( v, w, timeneed( v, w));
            if(z <= d) {
                printf("%.6f\n", timeneed(0,v) + timeneed(v,w) + (d-z) / v + solve( w, l - d));
            }
            else {
                double L = w, R = v;
                for(int kk=0;kk<55;++kk) {
                    double M = (L+R) / 2;
                    double zz = getlen(0, M, timeneed( 0, M)) + getlen( M, w, timeneed(M, w));
                    if(zz > d) R = M;
                    else L = M;
                }
                printf("%.6f\n", timeneed( 0, L) + timeneed( L, w) + solve( w, l-d));
            }
        }
    }
    return 0;
}