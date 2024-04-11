#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int step = 1, cur = 0;
    
    for(int i = 0; i < n - 1; ++i) {
            cur = (cur + step) % n;
            step++;
            cout << cur + 1 << " ";
    }
    
    cin >> n;
    
    return 0;
}