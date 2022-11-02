#include <iostream>
#include <string>
using namespace std;

bool is_glasn(char c) {
     return c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o';
}

int count_gl(string s) {
    int res = 0;
    for(int i = 0; i < s.length(); ++i)
            if(is_glasn(s[i]))
                              ++res;
    return res;
}

int main() {
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    
    cout << (count_gl(a) == 5 && count_gl(b) == 7 && count_gl(c) == 5 ? "YES" : "NO");
    
    return  0;
}