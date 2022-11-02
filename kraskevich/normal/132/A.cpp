#include <iostream>
#include <string>
#include <vector>
using namespace std;

int bit(int mask, int n) {
    return mask & (1 << n) ? 1 : 0;
}

int rev(int a) {
    int res = 0;
    for(int i = 0; i < 8; ++i)
            res = res | ((1 << (7 - i)) * bit(a, i));
    return res;
}

int main() {
    string s;
    int prev = 0;
    
    getline(cin, s);
    
    for(int i = 0; i < s.length(); ++i) {
            int cur = (256 + prev - rev(s[i])) % 256;
            cout << cur << endl;
            prev = rev(s[i]);
    }
    
    cin >> s;
    
    return 0;
}