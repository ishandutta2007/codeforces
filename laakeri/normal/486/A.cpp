#include <iostream>

using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll a=n/2ll;
    if (n%2ll==1ll){
        a-=n;
    }
    cout<<a<<endl;
}