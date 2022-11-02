#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    for(int i = 0; i < s.length(); ++i)
            if(s[i] == 'H' || s[i] == '9' || s[i] == 'Q') {
                    cout << "YES";
                    return 0;
    }
    
    cout << "NO";        
    return 0;
}