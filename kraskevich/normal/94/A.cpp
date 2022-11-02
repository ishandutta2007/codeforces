#include <iostream>
using namespace std;

string cp(string s, int l, int r) {
       string res = "";
       for(int i = l; i < r; ++i)
               res += s[i];
       return res;
}

int main() {
    string s;
    
    cin >> s;
    
    string t[10];
    
    for(int i = 0; i < 10; ++i)
            cin >> t[i];
    
    for(int i = 0; i + 10 <= s.length(); i += 10) 
            for(int j = 0; j < 10; ++j) 
                    if(cp(s, i , i + 10) == t[j]) {
                             cout << j;
                             break;
                    }
    
    cin >> s;
    return 0;
}