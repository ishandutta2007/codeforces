#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    LL n, s;
    cin >> n >> s;
    vector<LL> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int m = (n-1)/2;
    LL ans = 0 ;
    for(int i = 0; i <= m; i++){
        if(a[i] > s){
            ans += (a[i] - s);
        }
    }
    for(int i = m; i < n; i++){
        if(a[i] < s){
            ans += -(a[i] - s);
        }
    }
    cout << ans << endl;
}