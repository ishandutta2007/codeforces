#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
   int n;
   string s;
   

cin >> n;   cin >> s;
   
   if(n % 2 == 0) {
        for(int i = 0; i + 1 < n - 2; i += 2)
                cout << s[i] << s[i + 1] << "-";
        cout << s[n - 2] << s[n - 1];
   }
   else{
         for(int i = 0; i + 1 < n - 3; i += 2)
                cout << s[i] << s[i + 1] << "-";
        cout << s[n - 3] << s[n - 2] << s[n - 1];
   }
   
   cout << endl;
   cin >> s;
   
   return 0;
}