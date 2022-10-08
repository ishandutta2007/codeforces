
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    for(int i = 0; i <= n; i++) {
        int cnt1 = 0, cnt2 = 0;
        for(int j = 0; j < i; j++) cnt1 += (s[j] == '(');
        for(int j = i; j < n; j++) cnt2 += (s[j] == ')');
        if(cnt1 == 0 && cnt2 == 0) {
            cout << 0 << endl;
            return 0;
        }else if(cnt1 == cnt2) {
            cout << 1 << endl << cnt1 + cnt2 << endl;
            for(int j = 0; j < i; j++) {
                if(s[j] == '(') {
                    cout << j + 1 << " ";
                }
            }
            for(int j = i; j < n; j++) {
                if(s[j] == ')') {
                    cout << j + 1 << " ";
                }
            }
            cout << endl;
            return 0;
        }
    }
    assert(false);
}