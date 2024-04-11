#include <iostream>
#include <string>
using namespace std;

string inttostr(int n) {
       string res = "";
       while(n) {
               res = char((n % 10) + '0') + res;
               n /= 10;
       }
       return res;
}

int main() {
    int n;
    cin >> n;
    string ans[n];
    for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            if(s.length() <= 10)
                             ans[i] = s;
            else
                ans[i] = s[0] + inttostr(s.length() - 2) + s[s.length() - 1];
    }
    for(int i = 0; i < n; ++i)
            cout <<  ans[i] << endl;
    cin >> n;
    return 0;
}