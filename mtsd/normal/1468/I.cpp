#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
typedef long long ll;
ll prod(pair<ll,ll>&a,pair<ll,ll>&b){
    return a.first * b.first + a.second*b.second;
}

int main(){
    int n;
    cin >> n;
    pair<ll,ll> a,b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    if(a==make_pair(0LL,0LL)||b==make_pair(0LL,0LL)){
        cout << "NO\n";
        return 0;
    }
    while(1){
        if(a==make_pair(0LL,0LL)||b==make_pair(0LL,0LL)){
            cout << "NO\n";
            return 0;
        }
        if(prod(a,a)>prod(b,b)){
            swap(a,b);
        }
        ll K = prod(a,b);
        ll s = prod(a,a);
        K /= s;
        ll res = (1LL<<60);
        pair<ll,ll> t;
        for(ll i = K-2;i<=K+2;i++){
            pair<ll,ll> X = make_pair(b.first-a.first*i,b.second-a.second*i);
            if(res>prod(X,X)){
                t = X;
                res = prod(X,X);
            }
        }
        if(b==t){
            break;
        }
        b = t;
        // cerr << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
    }
    // cerr << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
    if(a.first<0){
        a.first *= -1;
        a.second *= -1;
    }
    if(b.first<0){
        b.first *= -1;
        b.second *= -1;
    }
    if(a.first * b.second - b.first*a.second < 0){
        swap(a,b);
    }else if(a.first * b.second - b.first*a.second == 0){
        cout << "NO\n";
        return 0;
    }
    swap(a,b);
    // cerr << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
    ll res = 0;
    for(ll i=0;i<a.first+b.first;i++){
        long double U,L;
        ll u,l;
        if(i<a.first){
            U = (long double)i*(a.second)/(long double)a.first;
            u = floor(U);
            for(ll k = u-5;k<=u+5;k++){
                if(a.first*k <= i*a.second ){
                    u = k;
                }
            }
        }else{
            U = (long double)(i-a.first)*(b.second)/(long double)b.first;
            u = floor(U);
            for(ll k = u-5;k<=u+5;k++){
                if(k*b.first < (i-a.first)*(b.second) ){
                    u = k;
                }
            }
            u += a.second;
        }
        if(i<b.first){
            L = (long double)i*(b.second)/(long double)b.first;
            l = ceil(L);
            for(ll k = l-5;k<=l+5;k++){
                if(k*b.first < i*(b.second) ){
                    l = k+1;
                }
            }
        }else{
            L = (long double)(i-b.first)*(a.second)/(long double)a.first;
            l = ceil(L);
            for(ll k = l-5;k<=l+5;k++){
                if(k*a.first <= (i-b.first)*(a.second) ){
                    l = k+1;
                }
            }
            l += b.second;
        }
        // cerr << i << " " << u << " " << l << endl;
        res += u-l+1;
    }
    // cerr << res << endl;
    if(n==res){
        cout << "YES\n";
        vector<pair<ll,ll> > ans;
        for(ll i=0;i<a.first+b.first;i++){
            long double U,L;
            ll u,l;
            if(i<a.first){
                U = (long double)i*(a.second)/(long double)a.first;
                u = floor(U);
                for(ll k = u-5;k<=u+5;k++){
                    if(a.first*k <= i*a.second ){
                        u = k;
                    }
                }
            }else{
                U = (long double)(i-a.first)*(b.second)/(long double)b.first;
                u = floor(U);
                for(ll k = u-5;k<=u+5;k++){
                    if(k*b.first < (i-a.first)*(b.second) ){
                        u = k;
                    }
                }
                u += a.second;
            }
            if(i<b.first){
                L = (long double)i*(b.second)/(long double)b.first;
                l = ceil(L);
                for(ll k = l-5;k<=l+5;k++){
                    if(k*b.first < i*(b.second) ){
                        l = k+1;
                    }
                }
            }else{
                L = (long double)(i-b.first)*(a.second)/(long double)a.first;
                l = ceil(L);
                for(ll k = l-5;k<=l+5;k++){
                    if(k*a.first <= (i-b.first)*(a.second) ){
                        l = k+1;
                    }
                }
                l += b.second;
            }
            for(int j=l;j<=u;j++){
                ans.push_back(make_pair(i,j));
            }
        }
        for(auto x:ans){
            cout << x.first << " " << x.second << "\n";
        }
    }else{
        cout << "NO\n";
    }
    return 0;
}