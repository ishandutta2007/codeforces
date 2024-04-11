#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
bool solve(){
    string h, p;
    cin >> p >> h;
    int n = p.length(), m = h.length();
    sort(p.begin(), p.end());
    for(int i = 0 ; i + n - 1< m ; i ++){
        string res;
        for(int j = 0  ;j < n ; j ++){
            res += h[i + j];
        }
        sort(res.begin(), res.end());
        if(res == p) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    for(cin >> t ; t -- ; ){
        printf(solve() ? "YES\n" : "NO\n");
    }
}