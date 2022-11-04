#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s, t;

void solve(){
    cin >> s >> t;

    while(!t.empty()){
        if(s.empty()){
            cout << "NO";
            return;
        }

        if(s.back() == t.back()){
            s.pop_back(), t.pop_back();
        }else{
            s.pop_back();
            if(!s.empty()) s.pop_back();
        }
    }

    cout << "YES";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}