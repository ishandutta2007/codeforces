#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    int a[n];
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans = max(min(a[i]-1, 1000000-a[i]), ans);
    }
    cout << ans << endl;
}