#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
int ok1(int x, int y){
    if(x > n || y > n) return 0;
    cout << "?" << " " << x << " " << y << " " << n << " " << n << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return (ans == "YES");
}
int ok2(int x, int y){
    if(x < 0|| y < 0) return 0;
    cout << "?" << " " << 1 << " " << 1 << " " << x << " " << y << endl;
    fflush(stdout);
    string ans;
    cin >> ans;
    return (ans == "YES");
}
int main(){
    cin >> n;
    int cx = 1;
    int cy = 1;
    string ans1;
    while(cx + cy < n + 1){
        if(ok1(cx, cy + 1)){
            cy++;
            ans1 += 'R';
        } else {
            cx++;
            ans1 += 'D';
        }
    }
    int dx = n;
    int dy = n;
    string ans2;
    while(dx + dy > n + 1){
        if(ok2(dx - 1, dy)){
            dx--;
            ans2 += 'D';
        } else {
            dy--;
            ans2 += 'R';
        }
    }
    assert(cx == dx && cy == dy);
    reverse(ans2.begin(), ans2.end());
    cout << "!" << " " << ans1 + ans2 << '\n';
}