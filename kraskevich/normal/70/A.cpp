#include <iostream>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int ans = 1;
    for(int i = 1; i < n; ++i)
            ans = (ans * 3) % (1000 * 1000 + 3);
    
    cout << ans << endl;
    
    cin >> n;
    
    return 0;
}