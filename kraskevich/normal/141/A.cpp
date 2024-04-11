#include <iostream>
#include <string>
using namespace std;

int main() {
   string a, b, res;
   
   cin >> a >> b >> res;
   
   int c1[256], c2[256];
   
   for(int i = 0; i < 256; ++i)
           c1[i] = c2[i] = 0;
           
   for(int i = 0; i < a.length(); ++i)
           c1[a[i]]++;
   for(int i = 0; i < b.length(); ++i)
           c1[b[i]]++;
   for(int i = 0; i < res.length(); ++i)
           c2[res[i]]++;
   for(int i = 0; i < 256; ++i)
           if(c1[i] != c2[i]) {
                    cout << "NO";
                    return 0;
           }
   
   cout << "YES";
   
   return 0;
}