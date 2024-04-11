#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    double a, b, c;
    cin >> a >> b >> c;
    if(a < 0){
        a = -a; b = -b; c = -c;
    }
    double r1 = (-b + sqrt(b*b-4.0*a*c))/(2.0*a);
    double r2 = (-b - sqrt(b*b-4.0*a*c))/(2.0*a);
    printf("%.10lf\n%.10lf\n", r1, r2);
}