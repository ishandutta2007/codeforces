#include <iostream>
using namespace std;

int Abs(int y) {
    return y > 0 ? y : -y;
}

int main() {
    int a, x, y;
    
    cin >> a >> x >> y;
    
    
    swap(x, y);
    
    int cnt = 0, curX = 0, pos = 1;
    
    while(curX + a <= x) {
               curX += a;
               cnt += ((pos < 3 || pos % 2 == 0) ? 1 : 2);
               pos++;
    }
    if(curX == x) {
            cout << -1;
            cin >> a;
            return 0;
    }
    int t = (pos < 3 || pos % 2 == 0 ? 1 : 2);
    if(t == 1) {
         if(Abs(y) * 2 >= a) {
                   cout << -1;
                   cin >> a;
                   return 0;
         }
         else
             if(curX == x) {
                     cout << -1;
                     cin >> a;
                     return 0;
             }
             else
                 cout << cnt + 1;
    }
    else {
         if(Abs(y) >= a || curX == x || y == 0) {
                   cout << -1;
                   cin >> a;
                   return 0;
         }
         else
             cout << (y > 0 ? cnt + 2 : cnt + 1);
    }
    
    cin >> a;
    return 0;
}