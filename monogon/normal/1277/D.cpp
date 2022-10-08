
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
string str;
set<string> s01, s10;
map<string, int> m;

string reverse(const string &s) {
    string t = s;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        t[i] = s[n - i - 1];
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        s01.clear();
        s10.clear();
        m.clear();
        int n00 = 0, n11 = 0;
        for(int i = 0; i < n; i++) {
            cin >> str;
            m[str] = i;
            if(str.front() == '0') {
                if(str.back() == '0') {
                    n00++;
                }else {
                    s01.insert(str);
                }
            }else {
                if(str.back() == '0') {
                    s10.insert(str);
                }else {
                    n11++;
                }
            }
        }
        int n01 = s01.size();
        int n10 = s10.size();
        if(n00 > 0 && n11 > 0 && n01 == 0 && n10 == 0) {
            cout << -1 << endl;
            continue;
        }
        int cnt = abs(n01 - n10) / 2;
        cout << cnt << endl;
        if(n10 < n01)
            for(string str : s01) {
                if(cnt == 0) break;
                if(s10.count(reverse(str)) == 0) {
                    cnt--;
                    cout << m[str] + 1 << " ";
                }
            }
        else
            for(string str : s10) {
                if(cnt == 0) break;
                if(s01.count(reverse(str)) == 0) {
                    cnt--;
                    cout << m[str] + 1 << " ";
                }
            }
        cout << endl;
    }
}