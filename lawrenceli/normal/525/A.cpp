#include <bits/stdc++.h>
using namespace std;

int n, freq[30];
char s[200100];

int main() {
    cin >> n >> s;
    int ans = 0;
    for (int i=0; i<n-1; i++) {
        freq[s[2*i]-'a']++;
        if (!freq[s[2*i+1]-'A']) ans++;
        else freq[s[2*i+1]-'A']--;
    }
    cout << ans;
}