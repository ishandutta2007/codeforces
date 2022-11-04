#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, a, b, c;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        cout << (a<c?1:-1) << ' ' << (a*b>c?b:-1) << '\n';
    }
}