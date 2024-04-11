#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    
    cin >> s;
    
    int res = 0, i = s.length() - 1;
    
   while(i > 0) {
           if(s[i] == '0') {
                   --i;
                   ++res;
           }
           else {
                res++;
                while(i >= 0 && s[i] == '1') {
                        ++res;
                        --i;
                }
                if(i > 0)
                     s[i] = '1';
           }
   }
   
   cout << res;
   
   cin >> s;
   
   return 0;
}