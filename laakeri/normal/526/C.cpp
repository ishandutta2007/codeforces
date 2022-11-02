#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll c,hr,hb,wr,wb;
    cin>>c>>hr>>hb>>wr>>wb;
    if (wr<wb){
        swap(wr, wb);
        swap(hr, hb);
    }
    ll v=0;
    if (wr>=1000){
        for (ll i=0;i*wr<=c;i++){
            v=max(v, i*hr+((c-i*wr)/wb)*hb);
        }
    }
    else{
        ll mm=1e6+10;
        for (ll i=0;i<=mm&&i*wr<=c;i++){
            v=max(v, i*hr+((c-i*wr)/wb)*hb);
        }
        for (ll i=0;i<=mm&&i*wb<=c;i++){
            v=max(v, i*hb+((c-i*wb)/wr)*hr);
        }
    }
    cout<<v<<endl;
}