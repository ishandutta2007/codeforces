#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    int res = 0, k = 1;
    
    for(int i = 1; i < s.length(); ++i)
            if(s[i] == s[i - 1])
                    ++k;
            else {
                 res += (k - 1) / 5 + 1;
                 k = 1;
            }
    
    cout << res + (k - 1) / 5 + 1;
    
    cin >> s;
    
    return 0;
}