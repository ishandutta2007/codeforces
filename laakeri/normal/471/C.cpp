#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll need=0;
    ll v=0;
    ll nm=0;
    for (ll i=1ll;i<1000000ll;i++){
        need+=3ll*i-1ll;
        if (n<need) break;
        nm+=2ll;
        nm%=3ll;
        if (n%3ll==nm) v++;
    }
    cout<<v<<endl;
}