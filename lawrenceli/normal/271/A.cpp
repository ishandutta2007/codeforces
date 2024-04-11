#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int y;
    cin >> y;
    for (int i=y+1; true; i++) {
        int a=(i%10000-i%1000)/1000, b=(i%1000-i%100)/100, c=(i%100-i%10)/10, d=i%10;
        if (a!=b && a!=c && a!=d && b!=c && b!=d && c!=d) {
            cout << i << endl;
            return 0;
        }
    }
}