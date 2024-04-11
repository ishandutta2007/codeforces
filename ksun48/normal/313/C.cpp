#include <iostream>
#include <algorithm>
using namespace std;
int stuff[3000000];
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> stuff[i];
    for(int i = 0; i < n; i++) stuff[i] = -stuff[i];
    sort(stuff, stuff + n);
    for(int i = 0; i < n; i++) stuff[i] = -stuff[i];
    long long ans = 0;
    while(n > 0){
        for(int i = 0; i < n; i++){
            ans += stuff[i];
        }
        n /= 4;
    }
    cout << ans << endl;
    return 0;
}