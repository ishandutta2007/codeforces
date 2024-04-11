#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    
    int maxN = -100000;
    string name;
    
    for(int i = 0; i < n; ++i) {
            string s;
            int good, bad, a, b, c, d, e;
            
            cin >> s >> good >> bad >> a >> b >> c >> d >> e;
            int cur = 100 * good - 50 * bad + a + b + c + d + e;
            if(cur > maxN) {
                   name = s;
                   maxN = cur;
            }
    }
    
    cout << name << endl;
    
    return 0;
}