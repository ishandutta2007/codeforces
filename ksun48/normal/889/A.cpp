#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n;
    cin >> n;
    int ok[n+1];
    for(int i = 0; i <= n; i++){
        ok[i] = 1;
    }
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        ok[a] = 0;
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans += ok[i];
    }
    cout << ans << endl;
}