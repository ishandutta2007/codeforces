#include <iostream>

using namespace std;

typedef long long ll;

ll fs(ll n){
    if (n==0ll) return 0ll;
    ll tp=1;
    ll p=0;
    while (tp*10ll<=n){
        tp*=10ll;
        p++;
    }
    ll k=1;
    while ((k+1ll)*tp<=n){
        k++;
    }
    ll bv=p*45ll*(tp/10ll);
    ll v=bv*k+(((k-1ll)*k)/2ll)*tp+k*(n-tp*k+1ll);
    return v+fs(n-tp*k);
}

int main(){
    ll n;
    cin>>n;
    ll a=1;
    ll b=1e17;
    ll ys=0;
    while (a<=b){
        ll m=(a+b)/2ll;
        ys=fs(m);
        if (ys>=n){
            b=m-1ll;
        }
        else{
            a=m+1ll;
        }
    }
    ll hi=a;
    ys=fs(hi);
    if (ys==n){
        cout<<1<<" "<<hi<<endl;
        return 0;
    }
    while (true){
        ll a=1;
        ll b=hi-1ll;
        while (a<=b){
            ll m=(a+b)/2ll;
            ll s=fs(m);
            if (ys-s>n){
                a=m+1ll;
            }
            else if (ys-s==n){
                cout<<m+1ll<<" "<<hi<<endl;
                return 0;
            }
            else{
                b=m-1ll;
            }
        }
        hi++;
        ys=fs(hi);
    }
}