
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;
int cnt[26];
int n;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    int o = cnt['n' - 'a'];
    int z = cnt['z' - 'a'];
    for(int i = 0; i < o; i++) {
        cout << 1 << " ";
    }
    for(int i = 0; i < z; i++) {
        cout << 0 << " ";
    }
    cout << endl;
}