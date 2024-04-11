
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int n, m;
char c;
string s[N];
set<char> p;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(i < n - 1 && s[i][j] != '.' && s[i + 1][j] != '.' && s[i][j] != s[i + 1][j]) {
                if(s[i][j] == c) p.insert(s[i + 1][j]);
                else if(s[i + 1][j] == c) p.insert(s[i][j]);
            }
            if(j < m - 1 && s[i][j] != '.' && s[i][j + 1] != '.' && s[i][j] != s[i][j + 1]) {
                if(s[i][j] == c) p.insert(s[i][j + 1]);
                else if(s[i][j + 1] == c) p.insert(s[i][j]);
            }
        }
    }
    cout << p.size() << endl;
}