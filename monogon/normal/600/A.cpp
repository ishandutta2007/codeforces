
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;

bool isnum(string s) {
    if(s.length() == 0) return false;
    if(s == "0") return true;
    bool flag = s[0] > '0' && s[0] <= '9';
    for(int i = 1; i < s.length(); i++) {
        flag &= (s[i] >= '0' && s[i] <= '9');
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    s += ';';
    n = s.length();
    string t = "";
    string ans1 = "", ans2 = "";
    int cnt1 = 0, cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == ';' || s[i] == ',') {
            if(isnum(t)) {
                if(cnt1) ans1 += ',';
                ans1 += t;
                cnt1++;
            }else {
                if(cnt2) ans2 += ',';
                ans2 += t;
                cnt2++;
            }
            t = "";
        }else {
            t += s[i];
        }
    }
    if(!cnt1) ans1 = "-";
    else ans1 = "\"" + ans1 + "\"";
    if(!cnt2) ans2 = "-";
    else ans2 = "\"" + ans2 + "\"";
    cout << ans1 << "\n" << ans2 << "\n";
}