#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string a, b;
    
    cin >> a >> b;
    
    int already = 0, n = a.length();
    for(int i = 0; i < n; ++i)
            if(a[i] == b[i]) 
                    ++already;
    int cnt4t7 = 0, cnt7t4 = 0;
    for(int i = 0; i < n; ++i) {
            if(a[i] == '4' && b[i] == '7')
                    cnt4t7++;
            if(a[i] == '7' && b[i] == '4')
                    cnt7t4++;
    }
    int res = n;
    res -= already;
    res -= min(cnt4t7, cnt7t4);
    
    cout << res << endl;
    
    cin >> n;
    
    return 0;
}