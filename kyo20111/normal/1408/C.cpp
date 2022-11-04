#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, m;
double a[100100];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i=1;i<=n;i++) cin >> a[i];
        a[0] = 0;
        a[n+1] = m;

        int l = 0, r = n+1;
        double sl = 1, sr = 1;
        double ans = 0;

        while(l < r - 1){
            if((a[l+1] - a[l]) * sr == (a[r] - a[r-1]) * sl){
                if(l + 1 == r){
                    ans += (a[l+1] - a[l]) / sl / 2;
                    sl += 1, sr += 1;
                    l++, r--;
                    break;
                }

                ans += (a[l+1] - a[l]) / sl;
                sl += 1, sr += 1;
                l++, r--;
            }else if((a[l+1] - a[l]) * sr < (a[r] - a[r-1]) * sl){
                a[r] -= ((a[l+1] - a[l]) / sl) * sr;
                ans += (a[l+1] - a[l]) / sl;
                sl += 1;
                l++;
            }else{
                a[l] += ((a[r] - a[r-1]) / sr) * sl;
                ans += (a[r] - a[r-1]) / sr;
                sr += 1;
                r--;
            }
        }

        if(l < r){
            ans += (a[r] - a[l]) / (sl + sr);
        }
        cout << fixed << setprecision(12) << ans << "\n";
    }
}