#include <bits/stdc++.h>
using namespace std;

#define sz(v) ((int)(v).size())
#define pb push_back

int main()
{
    int k;
    string s;
    cin >> k >> s;
    int n = sz(s);
    vector <string> arr;
    vector <int> vis(128, 0);
    for (int i=0;i<n;i++){
        if (!vis[s[i]]) arr.pb(string(1, s[i]));
        else arr.back().pb(s[i]);
        vis[s[i]] = 1;
    }
    if (sz(arr) < k){ puts("NO"); return 0; }
    puts("YES");
    for (int i=0;i<k-1;i++) puts(arr[i].c_str());
    for (int i=k-1;i<sz(arr);i++) printf("%s", arr[i].c_str()); puts("");
}