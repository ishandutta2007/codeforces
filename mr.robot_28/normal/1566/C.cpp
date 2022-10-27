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
        int n;
        cin >> n;
        vector <bool> used(n);
        string s1, s2;
        cin >> s1 >> s2;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s1[i] == '0' && s2[i] == '1' || s1[i] == '1' && s2[i] == '0'){
                ans += 2;
                used[i] = 1;
            }
            else if(s1[i] == '0' && s2[i] == '0'){
                if(i != 0 && !used[i - 1] && s1[i - 1] == '1'){
                    ans += 2;
                    used[i - 1] = 1;
                    used[i] = 1;
                }
            }
            else if(s1[i] == '1' && s2[i] == '1'){
                if(i != 0 && !used[i - 1] && s2[i - 1] == '0'){
                    ans += 2;
                    used[i - 1] = 1;
                    used[i] = 1;
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(!used[i] && s1[i] == '0'){
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}