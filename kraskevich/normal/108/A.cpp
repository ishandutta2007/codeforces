#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

bool poly(int t) {
     int h = t / 60, m = t % 60;
     return h == ((m % 10) * 10 + m / 10);
}

int main() {
    string s;
    
    cin >> s;
    
    int h = (s[0] - '0') * 10 + s[1]  - '0', m = (s[3] - '0') * 10 + s[4] - '0', t = h * 60 + m;
    t = (t + 1) % (24 * 60);
    while(!poly(t))
                   t = (t + 1) % (24 * 60);
                   
    printf("%02d:%02d", t / 60, t % 60);
    
    cin >> s;
    return 0;
}