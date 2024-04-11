#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k, ava[300];
char s[nax];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s + 1;
    for(int i = 1 ;i <=  k; i ++){
        char x;
        cin >> x;
        ava[x] = true;
    }
    long long ans = 0;
    for(int i = 1 ;i <=n ;i ++){
        if(!ava[s[i]]) continue;
        int j = i;
        for(; j <= n && ava[s[j]] ; j ++){
            ans += j - i + 1;
        }
        i = j - 1 ;
    }
    cout << ans << '\n';

}