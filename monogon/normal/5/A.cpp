
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;
set<string> names;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll cnt = 0;
    while(getline(cin, s)) {
        if(s[0] == '+') {
            names.insert(s.substr(1));
        }else if(s[0] == '-') {
            names.erase(s.substr(1));
        }else {
            int i = 0;
            while(i < s.length() && s[i] != ':') i++;
            ll len = s.length() - i - 1;
            cnt += len * names.size();
        }
    }
    cout << cnt << endl;
}