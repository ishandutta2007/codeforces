#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    int state = 0;
    
    for(int i = 0; i < s.length(); ++i) {
            if(state == 0 && s[i] == 'h')
                     state++;
            if(state == 1 && s[i] == 'e')
                     state++;
            if((state == 2 || state == 3) && s[i] == 'l')
                      state++;
            if(state ==  4 && s[i] == 'o')
                     state++;
    }
    
    cout << (state == 5 ? "YES" : "NO");
    
    return 0;
}