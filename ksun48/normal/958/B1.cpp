#include<bits/stdc++.h>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i<n; i++){
        a[i] = 0;
    }
    for(int i = 1; i<n; i++){
        int aa, b;
        cin >> aa >> b;
        aa--;
        b--;
        a[aa]++;
        a[b]++;
    }
    int ans = 0;
    for(int i = 0; i<n; i++){
        if(a[i]==1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}