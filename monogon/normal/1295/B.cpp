
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, x;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x >> s;
        int cnt = 0;
        multiset<int> ms;
        for(int i = 0; i < n; i++) {
            ms.insert(cnt);
            cnt += (s[i] == '0') - (s[i] == '1');
        }
        if(cnt == 0) {
            cout << (ms.count(x) ? -1 : 0) << endl;
            continue;
        }
        int num = 0;
        for(int y : ms) {
            if(cnt > 0 && x >= y && (x - y) % cnt == 0) num++;
            if(cnt < 0 && y >= x && (y - x) % (-cnt) == 0) num++;
        }
        cout << num << endl;
    }
}