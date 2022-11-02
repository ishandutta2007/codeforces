#include <iostream>
#include <string>
using namespace std;

bool iscap(char c) {
     return c >= 'A' && c <= 'Z';
}

int count_cap(string s) {
    int res = 0;
    for(int i = 0; i < s.length(); ++i)
            if(iscap(s[i]))
                           ++res;
    return res;
}

char swap_size(char c) {
    if(iscap(c))
        return c - 'A' + 'a';
    else
        return c - 'a' + 'A';
}        
                          

int main() {
    string s;
    getline(cin, s);
    int t = count_cap(s);
    if(t == s.length() || (!iscap(s[0]) && t == s.length() - 1))
         for(int i = 0; i < s.length(); ++i)  
                 cout << swap_size(s[i]);
    else
        cout << s;
    cin >> s;
    return 0;
}