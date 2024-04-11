#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL powmod(LL a, LL n, LL m){
    if(n == 0) return 1 % m;
    if(n % 2) return (a * powmod(a,n-1,m)) % m;
    LL c = powmod(a, n/2, m);
    return (c*c) % m;
}
LL phi(LL n){
    LL result = n;
    for (LL p=2; p*p<=n; ++p){
        if (n % p == 0){
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
 
    if (n > 1){
        result -= result / n;
    }
    return result;
}

LL good(LL a, LL m){
    if(__gcd(a,m) == 1) return a;
    return good(a/__gcd(a,m),m);
}
vector<LL> phis;
vector<LL> w;

LL bigger(LL l, LL r, LL a){
    //cout << "bigger " << l << " " << r << " " << a << endl;
    if(a <= 1) return 1;
    if(l > r) return 0;
    if(w[l] == 1) return 0;
    LL g = 0;
    LL c = 1;
    while(c < a){
        g++;
        c *= w[l];
    }
    return bigger(l+1, r, g);
}

LL eval(LL l, LL r){
    if(l > r) return 1;
    if(w[l] == 1) return 1;
    LL g = eval(l+1, r);
    return powmod(w[l], g, 1000000000);
}

LL solve(LL l, LL r, LL c){
    if(phis[c] == 1) return 0;
    if(l == r) return w[l] % phis[c];
    if(bigger(l+1, r, 32)){
        LL e = solve(l+1, r, c+1);
        while(e <= 32) e += phis[c+1];
        //cout << l << " " << r << " " << w[l] << " " << e << endl;

        return powmod(w[l], e, phis[c]);
    } else {
        LL e = eval(l+1, r);
        //cout << l << " " << r << " " << w[l] << " " << e << endl;
        return powmod(w[l], e, phis[c]);
    }
}

int main(){
    LL n, m;
    cin >> n >> m;
    LL z = m;
    while(1){
        phis.push_back(z);
        if(z == 1) break;
        z = phi(z);
    }
    for(LL i = 0; i < n; i++){
        LL a;
        cin >> a;
        w.push_back(a);
    }
    LL q;
    cin >> q;
    for(LL i = 0; i < q; i++){
        LL l, r;
        cin >> l >> r;
        l--; r--;
        cout << solve(l, r, 0) << endl;
    }
}