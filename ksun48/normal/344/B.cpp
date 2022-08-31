#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if((a+b+c) % 2 != 0 || a+b<c||a+c<b||b+c<a){
        cout << "Impossible" << endl;
    } else {
        cout << (a+b-c)/2 << " " << (b+c-a)/2 << " " << (c+a-b)/2 << endl;
    }
    return 0;
}