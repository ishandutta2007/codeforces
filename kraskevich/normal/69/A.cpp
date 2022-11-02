#include <iostream>
using namespace std;

int main() {
    int n, sumX = 0, sumY = 0, sumZ = 0;
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            sumX += x;
            sumY += y;
            sumZ += z;
    }
    
    cout << (sumX == 0 && sumY == 0 && sumZ == 0 ? "YES" : "NO") << endl;
    
    return 0;
}