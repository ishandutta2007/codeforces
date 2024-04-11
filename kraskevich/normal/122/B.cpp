#include <iostream>
#include <string>
using namespace std;

int main() {
   int cnt7 = 0, cnt4 = 0;
   string s;
   
   cin >> s;
   
   for(int i = 0; i < s.length(); ++i) {
           if(s[i] == '4')
                   cnt4++;
           if(s[i] == '7')
                   cnt7++;
   }
   if(cnt4 == 0 && cnt7 == 0)
           cout << -1;
   else
       cout << (cnt4 >= cnt7 ? '4' : '7');
   
   return 0;
}