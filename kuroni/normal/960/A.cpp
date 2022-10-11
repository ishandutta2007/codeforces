#include <bits/stdc++.h>
using namespace std;
    
int cnt[3];
string s, t;
    
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    t = s;
    sort(t.begin(), t.end());
    for (char &c : t)
        cnt[c - 'a']++;
    cout << ((s == t && min(cnt[0], cnt[1]) > 0 && (cnt[2] == cnt[0] || cnt[2] == cnt[1])) ? "YES" : "NO");
}