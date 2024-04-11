#include <iostream>
using namespace std;

int main() {
    int n, k;
    
    cin >> n >> k;
    
    string s;
    
    cin >> s;
    
    int sum = 0;
    
    for(int i = 0; i < n - 1 && sum < k;) {
            if((i + 1) % 2 == 1) {
                  if(s[i] == '4' && s[i + 1] == '7') {
                          s[i] = s[i + 1] = '4';
                          i++;
                          sum++;
                  }
                  else
                      i++;
            }
            else {
                 if(s[i] != '4' || s[i + 1] != '7') 
                         ++i;
                 else {
                      if(s[i - 1] != '4') {
                           s[i] = '7';
                           s[i + 1] = '7';
                           ++sum;
                           i += 2;
                      }
                      else {
                           if((k - sum) % 2 == 0)
                                 s[i] = '4';
                           else
                                s[i] = '7';
                           break;
                      }
                 }
            }
    }
    cout << s << endl;
    
    cin >> n;
    
    return 0;
}