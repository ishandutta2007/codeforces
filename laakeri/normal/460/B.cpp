#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll pow(ll a, ll p){
    if (p==0) return 1;
    return a*pow(a, p-1);
}

int main(){
    vector<ll> ss;
    ll a,b,c;
    cin>>a>>b>>c;
    for (ll sx=1; sx<90; sx++){
        ll x=b*pow(sx, a)+c;
        if (x<(ll)1e9 && x>0){
            ll xx=x;
            ll s=0;
            while (xx){
                s+=xx%10;
                xx/=10;
            }
            if (s==sx){
                ss.push_back(x);
            }
        }
    }
    sort(ss.begin(), ss.end());
    cout<<ss.size()<<endl;
    for (ll s:ss){
        cout<<s<<" ";
    }
}