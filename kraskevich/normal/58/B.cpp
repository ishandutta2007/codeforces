#include <iostream>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int prev = n;
    for(int i = n; i >= 1; --i)
            if(prev % i == 0) {
                    cout << i << " ";
                    prev = i;
            }
    
    cin >> n;
    
    return 0;
}