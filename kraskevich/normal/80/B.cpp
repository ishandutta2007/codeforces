#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int h = (s[0] - '0') * 10  + s[1] - '0', m = (s[3] - '0')* 10 + s[4] - '0';
    
    if(h >= 12)
         h -= 12;
    
    cout.setf(ios::fixed);
    cout.precision(10);
    
    cout << (double)h / 12.0 * 360 + double(m) / (12.0 * 60.0) * 360  << " " << double(m) / 60.0 * 360;
    
    cin >> s;
    
    return 0;
}