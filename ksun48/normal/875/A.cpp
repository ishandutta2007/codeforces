#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL s(LL n){
    if(n == 0) return 0;
    return s(n/10) + (n % 10);
}
int main(){
    LL n;
    cin >> n;
    vector<LL> ans;
    for(LL c = n; c >= 0 && c >= n-200; c--){
        if(s(c) + c == n) ans.push_back(c);
    }
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for(LL i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}