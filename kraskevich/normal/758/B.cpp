#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    string s;
    cin >> s;
    int n = s.length();
    map<int, char> mod;
    for (int i = 0; i < n; i++)
        if (s[i] != '!')
            mod[i % 4] = s[i];
    map<char, int> ans;
    for (int i = 0; i < n; i++)
        if (s[i] == '!')
            ans[mod[i % 4]]++;
    cout << ans['R'] << " " << ans['B'] << " " << ans['Y'] << " " << ans['G'] << endl; 
}