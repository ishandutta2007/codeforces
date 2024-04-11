#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll k, c[10], u;
string s = "codeforces";
ll f(){
    ll re = 1;
    for(int i=0;i<10;i++) re *= c[i];
    return re;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> k;
    while(f() < k) c[u]++, u=(u+1)%10;
    for(int i=0;i<10;i++) for(int j=0;j<c[i];j++) cout << s[i];
}