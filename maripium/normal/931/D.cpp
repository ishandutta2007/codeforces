#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5 + 5;
int t[MN];
int nn[MN];
int r = 0;
signed main(){
    int n;
    cin >> n;//combinatoric
    t[1] = 0;
    for(int i = 2;i <= n;i++) {
        int u;
        cin >> u;
        t[i] = t[u] + 1;
    }
    for(int i = 2;i <= n;++i) {
       nn[t[i]]++;
    }
    int ans = 1;
    for(int i = 1;i <= MN - 5;++i)
    {
        ans += nn[i] % 2;
    }
    cout << ans << endl;
}