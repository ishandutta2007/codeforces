#include <bits/stdc++.h>
using namespace std; 

const int N = 1000*1000 + 10;

int cnt[27];

void solve() { 
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;

    memset(cnt, 0, sizeof cnt);

    for(auto x: a)
        cnt[x-'a']++;
    for(auto x: b)
        cnt[x-'a']--;

    for(int i = 0; i < 26; i++) {
        if(cnt[i] < 0 || cnt[i] % k) {
            cout << "No\n";
            return;
        }
        cnt[i+1] += cnt[i];
    }


    cout << "Yes" << '\n';
}

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}