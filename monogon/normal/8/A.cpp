
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s, a, b;
string ans[2][2] = {{"fantasy", "backward"}, {"forward", "both"}};

bool check() {
    int pos = s.find(a);
    if(pos == string::npos) return false;
    pos = s.find(b, pos + a.length());
    return pos != string::npos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> a >> b;
    bool b1 = check();
    s = string(s.rbegin(), s.rend());
    bool b2 = check();
    cout << ans[b1][b2] << endl;
}