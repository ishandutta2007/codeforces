#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n; string s, t; cin >> n >> s >> t;

    int ans = 0, z = 0, o = 0;

    for(int i=0;i<n;i++){
        if(s[i] != t[i]){
            ans += 2;
            if(z) ans++;
            o = z = 0;
        }else{
            if(s[i] == '0'){
                if(o) o = 0, ans += 2;
                else if(z) ans++;
                else z = 1;
            }else{
                if(z) z = 0, ans += 2;
                else o = 1;
            }
        }
    }

    cout << ans + z;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}