#include <iostream>
#include <string>
using namespace std;

char k;
string ppow = "6789TJQKA";

bool grt(char a, char b) {
     int i = 0, j = 0;
     while(ppow[i] != a)
                   ++i;
     while(ppow[j] != b)
                   ++j;
     return i > j;
}
     

bool is_bigger(string a, string b) {
     if(a[1] == b[1])
             return grt(a[0], b[0]);
     else
         return (a[1] == k ? true : false);
}

int main() {
    cin >> k;
    
    string a, b;
    
    cin >> a >> b;
    
    cout << (is_bigger(a, b) ? "YES" : "NO");
    
    cin >> a;
    
    return 0;
}