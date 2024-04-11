#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t;
string s;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> s;
        ll k = 0, mn = 0, ans = s.size();
        for(int i=0;i<s.size();i++){
            if(s[i] == '+') k++;
            else k--;
            if(k < mn){
                ans += (mn - k) * (i + 1);
                mn = k;
            }
        }
        cout << ans << '\n';
    }
}