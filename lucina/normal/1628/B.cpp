#include<bits/stdc++.h>
using namespace std;
const int A = 26;
char memo1[A][A][A];
char memo2[A][A];
void insert_memo(string v) {
    if (v.size() == 2) {
        memo2[v[0] - 'a'][v[1] - 'a'] = 1;
    } else {
        memo1[v[0] - 'a'][v[1] - 'a'][v[2] - 'a'] = 1;
    }
}
bool is_in(string v) {
    if (v.size() == 2) {
        return memo2[v[0] - 'a'][v[1] - 'a'];
    } else {
        return memo1[v[0] - 'a'][v[1] - 'a'][v[2] - 'a'];
    }
}
const int nax = 2e5 + 10;
int n;
string s[nax];

bool solve() {
    memset(memo1, 0, sizeof(memo1));
    memset(memo2, 0, sizeof(memo2));
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> s[i];
    }
    for (int i = n ; i >= 1 ; -- i) {
        if (s[i].size() == 1) return true;
        if (is_in(s[i])) return true;
        if (s[i].size() == 3) {
            if (s[i][0] == s[i][2]) return true;
            string v = s[i];
            v.pop_back();
            if (is_in(v)) return true;
        }
        if (s[i].size() == 2) {
            if (s[i][1] == s[i][0]) return true;
            for (char add = 'a' ; add <= 'z' ; ++ add) {
                s[i] += add;
                if (is_in(s[i])) return true;
                s[i].pop_back();
            }
        }
        reverse(s[i].begin(), s[i].end());
        insert_memo(s[i]);
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T-- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}