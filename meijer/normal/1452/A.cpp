#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int testCases;
    cin >> testCases;
    while(testCases--) {
        int x, y;
        cin>>x>>y;
        x=abs(x);
        y=abs(y);
        int ans = min(x,y)*2+max(0,abs(x-y)*2-1);
        cout << ans << endl;
    }
}