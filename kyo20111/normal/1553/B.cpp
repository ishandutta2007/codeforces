#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s, t;

void solve(){
    cin >> s >> t;

    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(s[j] != t[j-i]) break;

            int u = j-i+1, k = j-1;
            while(u < t.size() && k >= 0){
                if(t[u] != s[k]) break;
                k--, u++;
            }
            if(u == t.size()){
                cout << "YES";
                return;
            }
        }
    }

    cout << "NO";
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}