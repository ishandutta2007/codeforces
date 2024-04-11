#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    string s; cin >> s;

    bool flag = 1;
    for(auto x : s) if(x == '0') flag = 0;

    if(flag){
        cout << 0;
        return;
    }

    int l = 0, c = 0;
    for(auto x : s){
        if(x == '0'){
            if(!l) l = 1, c++;
        }else{
            l = 0;
        }
    }

    cout << min(c, 2);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}