#include <iostream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <queue>
#include <stack>

#define FOR(i,a,b) for(int i = a; i <= b; i++) 
#define DOWN(i,a,b) for(int i = a; i >= b; i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define FR(i,a) for(int i = 0; i < a; i++)
#define DR(i,a) for(int i = a-1; i >= 0; i--)
#define REP(i,a) for(int i = 0; i < a; i++)
#define Rep(i,a) for(int i = 0; i < a; i++)
#define For(i,a,b) for(int i = a; i <= b; i++)

#define sqr(x) (x)*(x)
#define dout debug && cout 
#define ll long long
#define sz size()
#define ull unsigned long long
#define pb push_back
#define oo 1000000002
/* DEBUGGING */
bool debug = false;
/* MAIN PROGRAM */

using namespace std;
/*************************TEMPLATE**********************************/
long long convertToNum(string s)
{
    long long val = 0; FR(i,s.size()) val = val * 10 + s[i] - '0';
    return val;
}
string convertToString(long long a) {
    string res = ""; if (!a) return "0";
    while (a) { res = (char)(a % 10 + 48) + res;  a /= 10; }
    return res;
}
long long GCD(long long x,long long y)  {
    if (!x) return y; if (!y) return x;
    if (x == y) return x; if (x < y) return GCD(x,y%x); else return GCD(x%y,y);
}
long long POW(long long x,long long y,long long Base){
    if (!y) return 1; long long u = POW(x,y/2,Base);
    u = (u * u) % Base;
    if (y & 1) return (u * x) % Base; else return u;
}
/**************************CODE HERE*****************************/
double A,B,C;
int main()
{
   // freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);   
    cin >> A >> B >> C;
    if (abs(A) < 1e-9 && abs(B) < 1e-9 && abs(C)<1e-9)
    {
        cout << -1 << endl;
        return 0;
    }
    if (abs(A)<1e-9 && abs(B)<1e-9 && C) 
    {
        cout << 0 << endl;
        return 0;
    }
    if (abs(A)<1e-9)
    {
        cout << 1 << endl;
        printf("%.6lf",-C/B);
        return 0;
    }
    double delta = B*B-4*A*C;
    if (delta < 0)
    {
        cout << 0 << endl;
        return 0;
    }
    double x1,x2;
    x1 = (-B - sqrt(delta))/(2*A);
    x2 = (-B + sqrt(delta))/(2*A);
    if (abs(delta) < 1e-9)
    {
        cout << 1 << endl;
        printf("%.6lf",x1);
        return 0;
    }
    cout << 2 << endl;
    if (x1 > x2)
    {
        double tg = x1;
        x1 = x2;
        x2 = tg;
    }
    printf("%.6lf\n%.6lf",x1,x2);
    return 0;
}