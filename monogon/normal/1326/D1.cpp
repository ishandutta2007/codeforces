
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e6 + 5;
int t, n;
string s, s2, s3;
int kmp[2 * N];

void makekmp(string s) {
    int i = 1, j = 0;
    int n = s.length();
    while(i < n) {
        if(s[i] == s[j]) kmp[i++] = ++j;
        else if(j == 0) kmp[i++] = 0;
        else j = kmp[j - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> s;
        n = s.length();
        int i = 0;
        for(i = 0; i < n; i++) {
            if(s[i] != s[n - i - 1]) break;
        }
        if(i == n) {
            cout << s << "\n";
        }else {
            s2 = s3 = s.substr(i, n - 2 * i);
            int k = s2.length();
            s2.push_back('*');
            for(int i = k - 1; i >= 0; i--) {
                s2.push_back(s2[i]);
            }
            makekmp(s2);
            string ans1 = s.substr(0, i) + s2.substr(0, kmp[(int) s2.length() - 1]) + s.substr(n - i);
            // cout << s2 << endl << kmp[(int) s2.length() - 1] << endl;
            
            reverse(s3.begin(), s3.end());
            s3.push_back('*');
            for(int i = k - 1; i >= 0; i--) {
                s3.push_back(s3[i]);
            }
            makekmp(s3);
            string ans2 = s.substr(0, i) + s3.substr(0, kmp[(int) s3.length() - 1]) + s.substr(n - i);
            // cout << s3 << endl << kmp[(int) s2.length() - 1] << endl;
            if(ans1.length() > ans2.length()) {
                cout << ans1 << "\n";
            }else {
                cout << ans2 << "\n";
            }
        }
    }
}