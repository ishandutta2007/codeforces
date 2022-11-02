#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n, m;
    
    cin >> n >> m;
    
    int sum = 0, cur = 0;
    
    while(sum + cur + 1 <= m) {
              sum += cur + 1;
              cur = (cur + 1) % n;
    }
    
    cout << m - sum;
    
    cin >> n;
    
    return 0;
}