#include <bits/stdc++.h>

using namespace std;

const int MAXN = 600000;

int CNT = 0;

const double pi = 3.141592653589793;
const double eps = 1e-9;

void solve() {
    int ans[4] = {0,0,0,0};
    map<char, int> m;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); ++i){
        if(s[i]!='!')
            m[s[i]] = i%4;
        else
            ans[i%4]++;
    }
    cout << ans[m['R']] << ' ' << ans[m['B']] << ' ' << ans[m['Y']] << ' ' << ans[m['G']] << endl;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("/home/step/CLionProjects/codeforces/input", "r", stdin);
    freopen("/home/step/CLionProjects/codeforces/output", "w", stdout);
#endif
    solve();
    return 0;
}