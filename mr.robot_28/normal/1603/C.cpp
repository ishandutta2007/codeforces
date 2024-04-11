#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long

using namespace std;

const int N = 3e5 + 100;
const int T = 700;
const int mod = 998244353;
pair <int, int> ptr[T];
pair <int, int> ptr1[T];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 0;
        ptr[0] = {a[n - 1], 1};
        int it = 1;
        for(int i = n - 2; i >= 0; i--){
            int it1 = 0;
            for(int j = 0; j < it; j++){
                int val = ptr[j].X;
                int k = (a[i] + val - 1) / val;
                int u1 = a[i] / k;
           //     cout << val << " " << i <<" " << u1 << " " << k << " " << ptr[j].Y << "\n";
                ans = (ans + (k - 1) * ptr[j].Y % mod * (i + 1)) % mod; 
                if(it1 != 0 && ptr1[it1 - 1].X == u1){
                    ptr1[it1 - 1].Y = (ptr1[it1 - 1].Y + ptr[j].Y) % mod;
                }
                else{
                    ptr1[it1++] = {u1, ptr[j].Y};
                }
            }
            if(it1 != 0 && ptr1[it1 - 1].X == a[i]){
                ptr1[it1 - 1].Y = (ptr1[it1 - 1].Y + 1) % mod;
            }
            else{
                ptr1[it1++] = {a[i], 1};
            }
            it = it1;
            for(int j = 0; j < it1; j++){
                ptr[j] = ptr1[j];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}