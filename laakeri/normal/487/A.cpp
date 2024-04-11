#include <iostream>

using namespace std;

typedef long long ll;

ll mhp,matk,mdef;

ll nhp(ll hp, ll atk, ll def){
    if (atk-mdef<=0) return 10000000;
    if (matk-def<=0) return 0;
    ll mt=mhp/(atk-mdef);
    if (mhp%(atk-mdef)) mt++;
    ll hpn=(matk-def)*mt+1ll;
    return max(0ll, hpn-hp);
}

int main(){
    ll hp,atk,def;
    cin>>hp>>atk>>def;
    cin>>mhp>>matk>>mdef;
    ll h,a,d;
    cin>>h>>a>>d;
    ll v=10000000;
    for (ll i=0;i<=10000;i++){
        for (ll ii=0;ii<=10000;ii++){
            v=min(v, nhp(hp, atk+i, def+ii)*h+i*a+ii*d);
        }
    }
    cout<<v<<endl;
}