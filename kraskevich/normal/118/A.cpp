#include <iostream>
#include <string>
using namespace std;

int lower_case(char c) {
    if(c >= 'a')
         return c;
    else
        return c + 'a' - 'A';
}

bool is_glasn(char c) {
     c = lower_case(c);
     return c == 'a' || c == 'o' || c == 'y' || c == 'i' || c == 'e' || c == 'u';
} 

int main() {
    string s, res = "";
    
    cin >> s;
    for(int i = 0; i < s.length(); ++i)
            if(!is_glasn(s[i]))
                               res += lower_case(s[i]);
                               
    for(int i = 0; i < res.length(); ++i)
            cout << '.' << res[i];
    cout << endl;
    
    return 0;
}