
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 3e5 + 5;
int n;
string s;
string let;
int cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || s[i] != s[i - 1]) {
            let.push_back(s[i]);
            cnt[j] = 1;
            j++;
        }else {
            cnt[j - 1]++;
        }
    }
    if(j % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < j / 2; i++) {
        if(let[i] != let[j - i - 1] || cnt[i] + cnt[j - i - 1] < 3) {
            cout << 0 << endl;
            return 0;
        }
    }
    if(cnt[j / 2] < 2) {
        cout << 0 << endl;
        return 0;
    }
    cout << cnt[j / 2] + 1 << endl;
}