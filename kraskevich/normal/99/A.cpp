#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;

int main() {
  string s;
  int i;
  
  cin >> s;
  
  string Int = "", Float = "";
  
  for(i = 0; i < s.length() && s[i] != '.'; ++i)
          Int += s[i];
  for(int j = i + 1; j < s.length(); ++j)
              Float += s[j];
   if(Int[Int.length() - 1] == '9') {
                       cout << "GOTO Vasilisa." << endl;
                       return 0;
   }
   if(Float != "" && Float[0] >= '5') 
            Int[Int.length() - 1]++;
   
   cout << Int << endl;
                
   cin >> s;
   
   return 0;            
}