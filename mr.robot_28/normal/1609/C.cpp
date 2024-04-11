#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
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
    vector <int> p(N, -1);
    for(int i = 2; i < N; i++){
        int j = i * 2;
        while(j < N){
            p[j] = 1;
            j += i;
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin >> n >> e;
        vector <int> a(n);
        vector <int> left(n);
        vector <int> right(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i - e >= 0 && a[i - e] == 1){
                left[i] = 1 + left[i - e];
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(i + e < n && a[i + e] == 1){
                right[i] = 1 + right[i + e];
            }
        }
        ll ans = 0;
        for(int i = 0; i < n;i++){
            if(a[i] != 1 && p[a[i]] == -1){
                ans += 1LL * (left[i] + 1) * (right[i] + 1) - 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}