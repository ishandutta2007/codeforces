#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int main(){
    ll n,l,x,y;
    cin>>n>>l>>x>>y;
    set<ll> as;
    for (int i=0;i<n;i++){
        ll a;
        cin>>a;
        as.insert(a);
    }
    int xf=0;
    int yf=0;
    for (ll a:as){
        if (as.count(a+x)){
            xf=1;
        }
        if (as.count(a+y)){
            yf=1;
        }
    }
    if (xf&&yf){
        cout<<0<<endl;
    }
    else if (xf){
        cout<<1<<endl;
        cout<<y<<endl;
    }
    else if(yf){
        cout<<1<<endl;
        cout<<x<<endl;
    }
    else {
        for (ll a:as){
            if (as.count(a+x+y)){
                cout<<1<<endl;
                cout<<a+x<<endl;
                return 0;
            }
            if (as.count(a+(y-x))){
                if (a+y<=l){
                    cout<<1<<endl;
                    cout<<a+y<<endl;
                    return 0;
                }
                if (a+(y-x)-y>=0){
                    cout<<1<<endl;
                    cout<<a+(y-x)-y<<endl;
                    return 0;
                }
            }
        }
        cout<<2<<endl;
        cout<<x<<" "<<y<<endl;
    }
}