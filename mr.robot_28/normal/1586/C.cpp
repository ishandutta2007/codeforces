#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    vector <int> pref(m + 1, 0);
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(s[i][j - 1] == 'X' && s[i - 1][j] == 'X'){
                pref[j + 1]++;
            }
        }
    }
    for(int j = 1; j <= m; j++){
        pref[j] += pref[j - 1];
    }
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if(pref[r + 1] - pref[l + 1] == 0){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}