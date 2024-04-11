#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int ok = 0;
    if(s == t) ok = 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '*' && (s.size() - 1)<= t.size()){
            string s1 = s.substr(0, i);
            string s2 = s.substr(i+1);
            if(t.substr(0, s1.size()) == s1 && t.substr(t.size() - s2.size()) == s2){
                ok = 1;
            }
        }
    }
    if(ok){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}