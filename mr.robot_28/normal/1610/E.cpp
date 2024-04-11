#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define sz(a) (int)a.size()
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 7;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    while(count--){
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i != 0 && a[i] == a[i - 1]){
                continue;
            }
            int sum = 1;
            int cur = i + 1;
            while(1){
                int t = lower_bound(a.begin() + cur, a.end(), 2 * a[cur - 1] - a[i]) - a.begin();
                if(t == n){
                    break;
                }
                cur = t + 1;
                sum++;
            }
            ans = max(ans, sum);
        }
        cout << n - ans << '\n';
    }
    return 0;
}