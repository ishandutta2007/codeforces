#include <iostream>
#include <string>
using namespace std;

int sum(int n) {
    int res = 0;
    while(n) {
             res += n % 10;
             n /= 10;
    }
    return res;
}    

int main() {
    string s;
    cin >> s;
    
    int res = 0;
    
    if(s.length() == 1) {
                  cout << 0;
                  return 0;
    }
    
    for(int i = 0; i < s.length(); ++i)
            res += s[i] - '0';
    
    int ans = 1;
    while(res >= 10) {
              ans++;
              res = sum(res);
    }
    
    cout << ans;
    
    cin >> res;
    
    return 0;
}