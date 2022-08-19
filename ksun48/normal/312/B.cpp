#include<iostream> // the solution is (a/b) /(1- (1 - a/b)(1-c/d))
#include<cstdio>

using namespace std;

double a, b, c, d, e, f, g;

int main() {
cin >> a >> b >> c >> d;
e = a/b, f = c / d;
cout << (e/(e+(1-e)*f )) << endl;
return 0;
}