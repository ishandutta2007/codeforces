#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
const int N = 2e5+10;
int fac[N], inv[N];

int add(int a, int b) {
    return (a+b)%mod;
}

int mul(int a, int b) {
    long long g = (1LL*a*b)%mod;
    return (int) g;
}

int power(int b, int p) {
    if(p == 0)
        return 1;

    int g = power(b,p/2);
    g = mul(g,g);
    if(p%2) g = mul(g,b);
    return g;
}

int inverse(int b) {
    return power(b,mod-2);
}

int binom(int n, int r) {
    return mul(fac[n],mul(inv[n-r],inv[r]));
}

int main() {
    //Pre-calc
    int cur = 1;
    for(int i=1;i<N;i++) {
        fac[i-1] = cur;
        inv[i-1] = inverse(fac[i-1]);
        cur = mul(cur,i);
    }
    int T;
    cin>>T;
    while(T--) {
        int n; cin>>n;
        string s;
        cin>>s;
        int counti = 0, mov = 0, dead = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '0') {
                mov += counti/2;
                dead += counti%2;
                counti = 0;
            }
            else {
                counti++;
            }
        }
        mov += counti/2;
        dead += counti%2;
        cout<<binom(mov+(n-2*mov-dead),mov)<<endl;
    }
    return 0;
}