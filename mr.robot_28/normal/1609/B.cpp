#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define int long long
#define ll long long
#define sz(a) (int)a.size()
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 7;
const int K = 1e7;
const int N = 1e6 + 1;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    set <int> st;
    for(int i = 0; i < n - 2; i++){
        if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
            st.insert(i);
        }
    }
    while(m--){
        int idx;
        cin >> idx;
        idx--;
        char c;
        cin >> c;
        for(int i = max(0LL, idx - 2); i <= idx; i++) {
            st.erase(i);
        }
        s[idx] = c;
        for(int i = max(0LL, idx - 2); i <= idx; i++) {
            if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c'){
                st.insert(i);
            }
        }
        cout << sz(st) << "\n";
    }
    return 0;
}