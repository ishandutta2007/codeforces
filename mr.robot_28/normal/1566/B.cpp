#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = sz(s);
        int st = -1, end = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '0'){
                if(st == -1){
                    st = i;
                }
                end = i;
            }
        }
        if(st == -1){
            cout << 0 << "\n";
            continue;
        }
        int cnt0 = 0, cnt1 = 0;
        for(int i = st; i <= end; i++){
            cnt0 += s[i] == '0';
            cnt1 += s[i] == '1';
        }
        if(cnt1 == 0){
            cout << 1 << "\n";
        }
        else{
            cout << 2 << "\n";
        }
    }
    return 0;
}