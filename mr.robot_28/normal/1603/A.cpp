#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long

using namespace std;

const int N = 3e5 + 100;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        vector <int> a(n);
        int s = 1;
        int resfl = 1;
        int fl = 0;
        int p = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            int t = __gcd(s, i + 2);
            if(p == 1 || 1e9 / ((i + 2) / t) < s){
                p = 1;
                continue;
            }
            fl = 0;
            s = ((i + 2) / t) * s;
            for(int j = 2; j <= i + 2; j++){
                if(a[i] % j != 0)
                {
                    fl = 1;
                }
            }
            if(!fl)
            {
                resfl = 0;
            }
        }
        if(resfl){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}