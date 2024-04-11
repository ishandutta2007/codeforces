/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

typedef long double ldb;

const ldb EPS= 1e-10;

int Q;

inline ldb check (ldb p, ldb q){
    if (q<1){
        return (ldb)1;
    }

    if (p-4*q < EPS){
        return ((p/(ldb)8) + q)/((ldb)2*q);
    }

    return 1 - q/p; 
}
/**********************************/
int main(){
    scanf ("%d", &Q);
    
    while (Q){
        int a,b; scanf ("%d%d", &a, &b);
        cout << fixed << setprecision(10) << check(a,b) << endl;
        Q--;
    }
    return 0;
}