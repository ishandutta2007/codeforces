
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int cnt = 0, prev = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            cnt++;
            if(cnt == 0) ans += i - prev + 1;
        }else {
            if(cnt == 0) prev = i;
            cnt--;
        }
    }
    cout << (cnt == 0 ? ans : -1) << endl;
}