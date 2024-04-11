#include<bits/stdc++.h>
using namespace std;
void pre(){}
long long int phi(long long int n) {
    long long int result = n;
    for (long long int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
int val(char c){return int(c)-int('a');}
void solve(){
    long long int a,m,t;cin>>a>>m;
    t = __gcd(a,m);
    m/=t;
    cout<<phi(m)<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}