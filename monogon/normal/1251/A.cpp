
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        s += '$';
        char prev = '$';
        int n = s.length();
        int cnt = 0;
        string ret = "";
        for(int i = 0; i < n; i++) {
            if(s[i] != prev) {
                if(cnt & 1) {
                    ret += prev;
                }
                cnt = 1;
                prev = s[i];
            }else {
                cnt++;
            }
        }
        sort(ret.begin(), ret.end());
        ret.erase(unique(ret.begin(), ret.end()), ret.end());
        cout << ret << endl;
    }
}