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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        int sum = 0;
        int koeff = 0;
        int maxa = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            while(a[i] % 2 == 0){
                a[i] /= 2;
                koeff++;
            }
            maxa = max(maxa, a[i]);
            sum += a[i];
        }
        sum -= maxa;
        cout << sum + maxa * (1LL << koeff) << "\n";
    }
    return 0;
}