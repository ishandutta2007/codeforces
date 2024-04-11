#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll n,m;
    cin>>n>>m;
    ll t=n/m;
    ll mm;
    if (n%m==0){
        mm=((t*(t-1ll))/2ll)*m;
    }
    else{
        ll t2=t+1;
        ll t2k=n%m;
        ll tk=m-n%m;
        mm=((t*(t-1ll))/2ll)*tk;
        mm+=((t2*(t2-1ll))/2ll)*t2k;
    }
    cout<<mm<<" "<<((n-m+1ll)*(n-m))/2ll<<endl;
}