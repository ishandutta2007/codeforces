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
 */

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

long long n;
long long a, b, c;

struct triple{
    long long x, y, d;

    triple (long long _x= -1, long long _y= -1, long long _d= -1) : x(_x), y(_y), d(_d) {}
};  
/******************************************/
inline triple gcd (long long a1, long long a2){
    if (a1== 0)
        return  triple(0, 1, a2);
    
    triple r= gcd(a2%a1,a1);
    return triple (r.y-(a2/a1)*r.x, r.x, r.d);
}
/******************************************/
int main (){
    cin >> a >> b >> c;
    if (c== 0){
        cout << b << ' ' << -a << endl;
        return 0;
    }
    triple ans= gcd(min(labs(a),labs(b)), max(labs(a),labs(b)));
    if ((c%ans.d)!= 0){
        cout << -1 << endl;
        return 0;
    }
    if (labs(b)< labs(a))
        swap (ans.x, ans.y);
    if (a < 0)
        ans.x= -ans.x;
    if (b < 0)
        ans.y= -ans.y;
    
    c= -c;
    cout << ans.x*((long long)(c/ans.d)) << ' ' << ans.y*((long long)(c/ans.d)) << endl;

    return 0;
}