#include <iostream>
using namespace std;

int main() {
    string s;
    int dem = 0;
    int res = 0;
    while(getline(cin, s)) {
        if(s[0] == '+') ++dem;
        else if(s[0] == '-') --dem;
        else {
            for(int i=0;i<s.length();++i) if(s[i] == ':') { res += dem * (s.length() - i - 1); break; }
            
        }
    }
    cout << res << endl;
    return 0;
}