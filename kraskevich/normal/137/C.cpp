#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct event {
       int a, b;
};

bool cmp(event a, event b) {
     return a.a < b.a || a.a == b.a && a.b > b.b;
}

int main() {
    int n;
    
    cin >> n;
    
    event t[n];
    
    for(int i = 0; i < n; ++i)
            cin >> t[i].a >> t[i].b;
    
    sort(t, t + n, cmp);
    
    int ans = 0, last = -1;
    
    for(int i = 0; i < n; ++i) {
            if(last > t[i].b)
                    ++ans;
            last = max(last, t[i].b);
    }
    
    cout << ans;
    
    cin >> n;
    
    return 0;
}