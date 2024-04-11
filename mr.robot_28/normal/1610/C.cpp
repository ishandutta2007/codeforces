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
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
            swap(a[i], b[i]);
        }
        vector <vector <int> > g(n + 1);
        int l = 0, r = n + 1;
        while(r - l > 1){
            int midd = (r + l) / 2;
            int c = 0;
            for(int i = 0; i < n; i++){
                if(a[i] >= c && midd - c - 1 <= b[i]){
                    c++;
                }
            }
            if(c >= midd){
                l = midd;
            }
            else{
                r = midd;
            }
        }
        cout << l << "\n";
    }
    return 0;
}