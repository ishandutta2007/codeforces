#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
ll t, s, q;
cin >> t >> s >> q;
ll ans = 0;
while(true){
s *= q;
s = min(s, t);
ans += 1;
if(s >= t) break;
}
cout << ans << '\n';
}