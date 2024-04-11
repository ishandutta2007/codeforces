
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += (s[i] == '0') - (s[i] == '1');
    }
    if(cnt != 0) {
        cout << 1 << endl << s << endl;
    }else {
        cout << 2 << endl << s[0] << " " << s.substr(1) << endl;
    }
}