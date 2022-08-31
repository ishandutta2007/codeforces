#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    string t;
    for(int i = 0; i < 2 * s.size(); i++){
        char f = s[i % s.size()];
        if(i % 2){
            f ^= 'w' ^ 'b';
        }
        t += f;
    }
    int ans = 0;
    int cur = 0;
    for(int i = 0; i < t.size(); i++){
        if(i > 0 && t[i] != t[i-1]) cur = 0;
        cur++;
        ans = max(ans, cur);
    }
    cout << min(ans, (int)s.size()) << '\n';
}