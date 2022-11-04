#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string s;

void solve(){
    cin >> s;
    cout << *max_element(s.begin(), s.end());
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}