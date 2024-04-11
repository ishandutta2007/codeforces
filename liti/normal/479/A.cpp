// In the name of Allah
#include <iostream>
#include <cmath>
using namespace std;
int main() { 
 int a,b,c;
 cin >> a >> b >> c;
 cout << max( a * b * c , max( ( a + b ) * c , max(a * (b + c ) , a + b + c ) ) ) << endl;
}