#include <iostream>
#include <string>
#include <set>
using namespace std;

void print(int n) {
     if(n == 0)
          cout << "S";
     if(n == 1)
          cout << "M";
     if(n == 2)
          cout << "L";
     if(n == 3)
          cout << "XL";
     if(n == 4)
          cout << "XXL";
     cout << endl;
}

int main() {
    int n[5];
    
    for(int i = 0; i < 5; ++i)
            cin >> n[i];
    
    int k;
    
    cin >> k;
    
    int s[k];
    
    for(int i = 0; i < k; ++i) {
            string str;
            cin >> str;
            if(str == "S")
                 s[i] = 0;
            if(str  == "M")
                    s[i] = 1;
            if(str == "L")
                   s[i] = 2;
            if(str == "XL")
                   s[i] = 3;
            if(str == "XXL")
                   s[i] = 4;
    }
    
    for(int i = 0; i < k; ++i) {
            int l = s[i], r = s[i];
            while(l >= 0 && n[l] == 0)
                     --l;
            while(r < 5 && n[r] == 0)
                    ++r;
            if(r == l) { 
                 print(l);
                 --n[l];
                 continue;
            }
            if(l == -1) {
                 print(r);
                 --n[r];
                 continue;
            }
            if(r == 5) {
                 print(l);
                 --n[l];
                 continue;
            }
            print(r - s[i] > s[i] - l ? l : r);
            --n[r - s[i] > s[i] - l ? l : r];
    }
    
    cin >> n[0];
    
    return 0;                
}