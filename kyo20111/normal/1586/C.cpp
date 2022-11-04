#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, q;
ll cnt[1001001];
string s[1001001];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> s[i];

    for(int j=2;j<=m;j++){
        for(int i=1;i<n;i++){
            if(s[i][j-1] == 'X' && s[i+1][j-2] == 'X') cnt[j]++;
        }
    }

    for(int j=2;j<=m;j++) cnt[j] += cnt[j-1];

    cin >> q;
    while(q--){
        int l, r; cin >> l >> r;

        if(cnt[r] - cnt[l] == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}