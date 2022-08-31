#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string s, t;
    cin >> s >> t;
    LL ans = 0;
    int st = 0;
    int en = 0;
    int n = s.size();
    map<char,int> g;
    g['R'] = 0; g['B'] = 1; g['G'] = 2;

    int freq[9][n];
    for(int j = 0; j < 9; j++){
        freq[j][0] = 0;
        for(int i = 1; i < n; i++){
            freq[j][i] = freq[j][i-1];
            if(g[s[i-1]] * 3 + g[s[i]] == j){
                freq[j][i]++;
            }
        }
    }
    for(int i = 0; i < t.size(); i++){
        while(en < n && s[en] != t[i]) en++;
        // all between st and en EXCEPT ?
        if(st < n){
            ans += min(en, n-1) - min(st, n-1) + 1;
            if(i > 0 && t[i] != t[i-1]){
                int l = g[t[i]] * 3 + g[t[i-1]];
                ans -= (freq[l][en-1] - freq[l][st]);
            }
        }
        if(s[st] == t[i]) st++;
        if(s[en] == t[i]) en++;
    }
    cout << ans << endl;
}