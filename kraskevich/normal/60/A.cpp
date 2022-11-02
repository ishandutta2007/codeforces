#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    int l = 1, r = n;
    for(int i = 0; i < m; ++i) {
            string s1, s2, s3, s4;
            cin >> s1 >> s2 >> s3 >> s4;
            int x;
            cin >> x;
            if(s3[0] == 'r') 
                          l = max(l, x + 1);
            else
                     r = min(x - 1, r);
    }
    if(l > r)
         cout << -1;
    else
        cout << r - l + 1;
    cin >> n;
    return 0;
}