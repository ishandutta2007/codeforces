#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) (int)a.size()
#define ll long long
const ll mod1 = 998244353;
const ll mod2 = 1e9 + 7;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int i = 0;
        while(i < n && a[i] == a[n - i - 1]){
            i++;
        }
        if(i == n){
            cout << "YES\n";
            continue;
        }
        vector <int> b, c;
        for(int j = 0; j < n; j++){
            if(a[j] != a[i]){
                b.push_back(a[j]);
            }
            if(a[j] != a[n - i - 1]){
                c.push_back(a[j]);
            }
        }
        bool fl1 = 1, fl2 = 1;
        for(int i = 0; i < sz(b); i++){
            if(b[i] != b[sz(b) - i - 1]){
                fl1 = 0;
            }
        }
        for(int i = 0; i < sz(c); i++){
            if(c[i] != c[sz(c) - i - 1]){
                fl2 = 0;
            }
        }
        if(fl1 || fl2){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}