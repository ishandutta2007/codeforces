
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int q, n;
string s;
map<char, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> s;
        n = s.length();
        cnt.clear();
        for(char c : s) {
            cnt[c]++;
        }
        int u = min(cnt['U'], cnt['D']);
        int r = min(cnt['R'], cnt['L']);
        if(u == 0) r = min(r, 1);
        if(r == 0) u = min(u, 1);
        cout << 2 * u + 2 * r << endl;
        for(int i = 0; i < u; i++) cout << 'U';
        for(int i = 0; i < r; i++) cout << 'R';
        for(int i = 0; i < u; i++) cout << 'D';
        for(int i = 0; i < r; i++) cout << 'L';
        cout << endl;
    }
}