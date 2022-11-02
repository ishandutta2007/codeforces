#include <bits/stdc++.h>

using namespace std;
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second
#define pb push_back
int t, px, py, cx, cy, dx, dy;
map<char, int> nums;
string s;

void solve() {
    nums.clear();
    cx=0, cy=0;
    cin >> px >> py;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i]=='L') cx--;
        else if (s[i]=='R') cx++;
        else if (s[i]=='U') cy++;
        else if (s[i]=='D') cy--;
        nums[s[i]]++;
    }
    if (cx==px && cy==py) {
        cout << "YES\n";
        return;
    }
    dx = cx-px;
    dy = cy-py;
    if (dx>0 && nums['R']<dx) {cout << "NO\n"; return;}
    if (dx<0 && nums['L']<abs(dx)) {cout << "NO\n"; return;}
    if (dy>0 && nums['U']<dy) {cout << "NO\n"; return;}
    if (dy<0 && nums['D']<abs(dy)) {cout << "NO\n"; return;}
    cout << "YES\n";
    return;
}

int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}