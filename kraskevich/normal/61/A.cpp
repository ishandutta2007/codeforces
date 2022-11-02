#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b, ans;
    
    cin >> a >> b;
    
    ans = a;
    
    for(int i = 0; i < a.length(); ++i)
            ans[i] = (a[i] == b[i] ? '0' : '1');
    
    cout << ans << endl;
    
    return 0;
}