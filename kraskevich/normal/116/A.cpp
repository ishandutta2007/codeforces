#include <iostream>
using namespace std;

int main() {
    int n, a, b, res = 0, cur = 0;
        
    cin >> n;
    for(int i = 0; i < n; ++i) {
            cin >> a >> b;
            cur = cur - a + b;
            res = max(res, cur);
    }
    
    cout << res << endl;
    
    return 0;
}