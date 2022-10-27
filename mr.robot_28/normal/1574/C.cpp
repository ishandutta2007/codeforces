#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
using namespace std;

const int N = 5e5 + 100;
const int T = 350;
const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> a(n);
    int suma = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        suma += a[i];
    }
    sort(a.begin(), a.end());
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        int i = lower_bound(a.begin(), a.end(), x) - a.begin();
        if(i == n){
            cout << x - a[n - 1] + max(0LL, y - (suma - a[n - 1])) << "\n";
        }
        else if(i == 0){
            cout << max(0LL, y - (suma - a[0])) << "\n";
        }
        else{
            cout << min(max(0LL, y - (suma - a[i])), x - a[i - 1] + max(0LL, y - (suma - a[i - 1]))) << "\n";
        }
    }
    return 0;
}