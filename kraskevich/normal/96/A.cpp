#include <string>
#include <iostream>
using namespace std;

int main() {
    int  k = 1;
    string s;
    
    cin >> s;
    
    for(int i = 1; i < s.length(); ++i) {
            if(s[i] == s[i - 1])
                    ++k;
            else
                k = 1;
            if(k >= 7) {
                 cout << "YES";
                 return 0;
            }
    }
    
    cout << "NO";
                 
    return 0;
}