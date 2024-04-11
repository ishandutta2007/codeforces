#include <iostream>
#include <string>
using namespace std;

int main() {
    int r1, r2, c1, c2, d1, d2;
    
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    
    for(int i = 1; i <= 9; ++i)
            for(int j = 1; j <= 9; ++j)
                    for(int k = 1; k <= 9; ++k)
                            for(int l = 1; l <= 9; ++l)
                                    if(k + l == r2 && i + j == r1 && i + k == c1 && j + l == c2 &&
                                       i + l == d1 && k + j == d2 && i != j && i != k && i != l && j != k && j != l && k != l) {
                                           cout << i << " " << j << endl << k << " " << l;
                                           cin >> r1;
                                           return 0;
                                       }
    
    cout << -1;
    
    return 0;
}