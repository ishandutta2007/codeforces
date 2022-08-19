#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    LL a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    LL ans = -1;
    if(a == 1){
        ans = 6 * (b / 6) + 2 * (b % 6 == 4) + 4 * (b % 6 == 5);
    } else if(a == 2){
        if(b == 2){
            ans = 0;
        } else if(b == 3){
            ans = 4;
        } else if(b == 7){
            ans = 12;
        } else {
            ans = 2 * b;
        }
    } else {
        ans = 2 * (a * b / 2);
    }
    cout << ans << '\n';
}