#include <iostream>
using namespace std;

typedef long long ll;

const int MAXN = 100005;
const ll MOD = 1000000007;

string a;
ll k, x;

ll exp(ll n, ll e) {
    if (e==0) return 1;
    ll b=exp(n, e/2);
    if (e%2) return (n*b*b)%MOD;
    return (b*b)%MOD;
}

ll pow(ll e) {
    if (e==1) return x;
    ll b=pow(e/2);
    ll c=b*(exp(2, (e/2)*a.length())+1)%MOD;
    if (!(e%2)) return c;
    return (c+x*exp(2, (e-1)*a.length())%MOD)%MOD;
}

int main() {
    cin >> a >> k;
    for (int i=0; i<a.length(); i++) {
        if (a[i]=='0' || a[i]=='5') x=(x+exp(2, i))%MOD;
    }
    cout << pow(k) << endl;
}