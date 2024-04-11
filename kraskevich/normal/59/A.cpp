#include <iostream>
#include <string>
using namespace std;

bool is_big(char c) {
    return c <= 'Z';
}

bool is_small(char c) {
     return c >= 'a';
}

char up_case(char c) {
     if(is_small(c))
                    return c - 'a' + 'A';
     else
         return c;
}

char low_case(char c) {
     if(!is_small(c))
                    return c - 'A' + 'a';
     else
         return c;
}

int main() {
    string s;
    cin >> s;
    
    int sm = 0, b = 0;
    for(int i = 0; i < s.length(); ++i) {
            sm += is_small(s[i]);
            b += is_big(s[i]);
    }
    for(int i = 0; i < s.length(); ++i)
                 cout << (b > sm ? up_case(s[i]) : low_case(s[i]));
    
    cin >> s;
     
    return 0;
}