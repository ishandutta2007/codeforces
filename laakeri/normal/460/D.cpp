#include <iostream>
#include <cstdlib>

using namespace std;

typedef long long ll;

ll l,r,k;

ll bm=1e14;
ll bv=0;
ll bvc=0;

void b(ll x, ll i, ll c, ll cc){
    if (c>k) return;
    //cout<<x<<" "<<i<<" "<<c<<" "<<cc<<endl;
    if (x<bm&&c){
        bm=x;
        bv=cc;
        bvc=c;
    }
    if (i+(ll)1<=r){
        b(x^(i+(ll)1), i+(ll)1, c+(ll)1, cc|((ll)1<<(i+(ll)1)-l));
        b(x, i+(ll)1, c, cc);
    }
}

int main(){
    cin>>l>>r>>k;
    if (r-l<(ll)16){
        b(l, l, 1, 1);
        b(0, l, 0, 0);
        cout<<bm<<endl;
        cout<<bvc<<endl;
        for (ll i=0;i<=r-l+(ll)1;i++){
            if (bv&((ll)1<<i)){
                cout<<l+i<<" ";
            }
        }
        cout<<endl;
        return 0;
    }
    if (k==(ll)1||r==l){
        cout<<l<<endl;
        cout<<1<<endl;
        cout<<l<<endl;
        return 0;
    }
    if (k>(ll)2){
        int f=0;
        ll v1,v2,v3;
        for (ll i=0;i<(ll)62;i++){
            if (((ll)1<<i)<=r && ((ll)1<<i)-(ll)1>=l){
                ll mi=min(((ll)1<<(i+(ll)1))-(ll)1, r);
                ll lol=((ll)1<<i);
                for (ll ii=i-(ll)1;ii>=0;ii--){
                    if (mi&((ll)1<<ii)){

                    }
                    else{
                        lol|=((ll)1<<ii);
                    }
                }
                if (lol<=r){
                    cout<<0<<endl;
                    cout<<3<<endl;
                    cout<<mi<<" "<<lol<<" "<<((ll)1<<i)-(ll)1<<endl;
                    return 0;
                }
            }
        }
    }
    if (k>(ll)3){
        for (ll i=l;i<l+(ll)100&&i<=r-(ll)3;i++){
            if ((((i^(i+(ll)1))^(i+(ll)2))^(i+(ll)3))==0) {
                cout<<0<<endl;
                cout<<4<<endl;
                cout<<i<<" "<<i+(ll)1<<" "<<i+(ll)2<<" "<<i+(ll)3<<endl;
                return 0;
            }
        }
    }
    if (k>(ll)1){
        for (ll i=l;i<l+(ll)100&&i<=r-(ll)1;i++){
            if ((i^(i+(ll)1))==(ll)1) {
                cout<<1<<endl;
                cout<<2<<endl;
                cout<<i<<" "<<i+(ll)1<<endl;
                return 0;
            }
        }
    }
}