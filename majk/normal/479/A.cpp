#include <iostream>
using namespace std;

int main() {
    int a,b,c; cin >> a >> b >> c;
    int d = max(a+b+c, a*b*c);
    d = max(d, (a+b)*c);
    d = max(d, (b+c)*a);
    d = max(d, a*b+c);
    d = max(d, a+b*c);
    cout << d << endl;
}