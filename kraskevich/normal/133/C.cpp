#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bit(int mask, int n) {
    return mask & (1 << n) ? 1 : 0;
}

int main() {
    string s;
    getline(cin, s);
    int prev = 0;
    for(int i = 0; i < s.length(); ++i) {
            int cur = (int)s[i], t = 0;
            for(int j = 0; j < 8; ++j) {
                    int bt = bit(cur, j);
                    t = t | (bt << (7 - j));
            }
            cout << (256 + prev - t) % 256 << endl;
            prev = t;
    }
    
    cin >> s;
     
    return 0;
}