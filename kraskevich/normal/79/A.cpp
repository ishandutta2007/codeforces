#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int x, y;
    
    cin >> x >> y;
    
    for(int i = 0;; ++i) {
            if(i % 2 == 0) {
                 int sum = 220;
                 if(x >= 2) {
                      x -= 2;
                      sum = 20;
                 }
                 else
                     if(x == 1) {
                          x = 0;
                          sum = 120;
                     }
                 int t = sum / 10;
                 if(t > y) {
                      cout << "Hanako";
                      cin >> x;
                      return 0;
                 }
                 y -= t;
            }
            else {
                 bool done = false;
                 int sum = 220;
                 if(y >= 22) {
                      y -= 22;
                      sum = 0;
                      done = true;
                 }
                 if(y < 12 && !done) {
                      if(y < 2) {
                           cout << "Ciel";
                           cin >> x;
                           return 0;
                      }
                      y -= 2;
                      sum = 200;
                      done = true;
                 }
                 if(y >= 12 && y < 22 && !done) {
                      y -= 12;
                      sum = 100;
                 }
                 int t = sum / 100;
                 if(t > x) {
                      cout << "Ciel";
                      cin >> x;
                      return 0;
                 }
                 x -= t;
            }
    }
}