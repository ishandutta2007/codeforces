
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, m;
string str, ans, c;
multiset<string> s;

string reversestr(string str) {
    string t;
    for(int i = (int) str.length() - 1; i >= 0; i--) {
        t.push_back(str[i]);
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        s.insert(str);
    }
    ans = c = "";
    while(!s.empty()) {
        str = *s.begin();
        s.erase(s.begin());
        string t = reversestr(str);
        if(s.count(t)) {
            s.erase(s.find(t));
            ans += str;
        }else if(str == t) {
            c = str;
        }
    }
    ans = ans + c + reversestr(ans);
    cout << ans.length() << endl << ans << endl;
}