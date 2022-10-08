
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    int cnt = 0;
    int cnt2 = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            cnt++;
        }else if(cnt == 0) {
            cnt2++;
        }else {
            cnt--;
        }
    }
    if((cnt2 == 0 && cnt == 0) || (cnt2 == 1 && cnt == 1)) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}