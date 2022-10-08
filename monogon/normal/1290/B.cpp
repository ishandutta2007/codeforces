
#include <bits/stdc++.h>

#define ll long long
using namespace std;

bool reducible(string s, string t) {
    int n = s.length();
    int cnt[26];
    for(int i = 0; i < 26; i++) cnt[i] = 0;
    for(int i = 0; i < n - 1; i++) {
        cnt[s[i] - 'a']++;
        cnt[t[i] - 'a']--;
        for(int j = 0; j < 26; j++) {
            if(cnt[j] != 0) goto endloop;
        }
        return true;
        endloop:;
    }
    return false;
}
bool irreducible(string s) {
    string t(s.begin(), s.end());
    sort(t.begin(), t.end());
    do {
        if(!reducible(s, t)) return true;
    }while(next_permutation(t.begin(), t.end()));
    return false;
}

const int N = 2e5 + 5;
int n, q, l, r;
string s;
int cnt[N][26];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.length();
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) {
            cnt[i][j] = cnt[i - 1][j];
        }
        cnt[i][s[i - 1] - 'a']++;
    }
    cin >> q;
    while(q--) {
        cin >> l >> r;
        if(s[l - 1] != s[r - 1] || l == r) {
            cout << "Yes" << endl;
            continue;
        }
        int k = 0;
        for(int j = 0; j < 26; j++) {
            if(cnt[r][j] != cnt[l - 1][j]) {
                k++;
            }
        }
        if(k <= 2) {
            cout << "No" << endl;
        }else cout << "Yes" << endl;
    }
}